long lt_cnt = 0;
long ge_cnt = 0;

int absdiff(int x, int y)
{
	if(x < y)
	{
		lt_cnt++;
		return y - x;
		//in fact, the subtraction here might cause overflow,
		//giving out an unexpected negative number.
		//but since we're not concerning if the code is robust,
		//we'll just leave that question there.
	}
	else
	{
		ge_cnt++;
	       	return x - y;
	}
}

int gotodiff(int x, int y)
{
	int result;
	if(x >= y) goto x_ge_y;
	lt_cnt++;
	result = y - x;
	return result;
x_ge_y:
	ge_cnt++;
	result = x - y;
	return result;
}

/*
 * run objdump -d and you can find that:
 * (note: the assembly code for function absdiff and gotodiff is totally same.)
 * This indicates that GCC will deal conditional sentences like:
 * test/cmp condition:
 * 	jmp(if not condition) to FALSE:
 * 	then sentences;
 * 	jmp to DONE;
 * FALSE:
 * 	else sentences;
 * DONE:
 * 	...
 * 0000000000000000 <absdiff>:
   0:   f3 0f 1e fa             endbr64
   4:   39 f7                   cmp    %esi,%edi
   6:   7d 0d                   jge    15 <absdiff+0x15>
   8:   48 83 05 00 00 00 00    addq   $0x1,0x0(%rip)        # 10 <absdiff+0x10>
   				^
			       /_\
			        |
				|
				the source code is ++(increament), but we can see that GCC assembled it to
				the instruction "addq". that's because instruction "inc" does not update 
				some of those condition flags such as OF, ZF, but will not update the remain.
			        (this is due to some historical issue)	
				This may cause mismatching of those conditional flags, so now CPU will take time
				to deal with it, and the program will turn out to be slower.
   f:   01
  10:   89 f0                   mov    %esi,%eax
  12:   29 f8                   sub    %edi,%eax
  14:   c3                      ret
  15:   48 83 05 00 00 00 00    addq   $0x1,0x0(%rip)        # 1d <absdiff+0x1d>
  					    ^
					   /_\
					    |
					    |
					    here we can see 0x0(%rip), that's because we defined variables in 
					    the global field. These variables will have a static position and 
					    will not be free till the program is over.
					    so, we can use PC-relative way to calculate its index.
					    the register %rip always points to the NEXT instructions to be processed.
					    (where r represents it's 64bits, 
					    and ip is the abbreviation for "instruction pointer")
					    note that %rip is different from the general registers, that it is
					    unwrittenable. you can't write
					    movq %rax, %rip to change its value.
					    but you can use conditional jumps, like:
					    jmp *%rax, then the program will jump to the address where %rax points to, 
					    indirectly changing register %rip.


					    the number 0x0 is the offset from %rip.
					    here assembler remains the number with 0x0, that's because the object file
					    is still not linked, so the actual address is still unkown.
					    it'll get updated as soon as the program is linked, since the addresses of those 
					    static variables will always remain the same at that time.
  1c:   01
  1d:   89 f8                   mov    %edi,%eax
  1f:   29 f0                   sub    %esi,%eax
  21:   c3                      ret
  */

// difficulty: **

// long cread_alt(long *xp) {
// 	long res = 0;
//	if(xp)res = *xp;
//	return res;
// }
// the function written like this will not be assembled by using conditional move.
// if you expected the assembly shows like:
// cread_alt:
// 	movl    $0, %eax
// 	testq    %rdi, %rdi
// 	cmovq    (%rdi), %rax
// 	ret
// then you are totally wrong.
//
// that's because the load instruction (%rdi) will happen before the conditional instruction accesses the flag.
// That is to say, whatever %rdi(xp) is nullptr or not, this program will load address from RAM, which may cause error.

// the correct way is, create a temporary variable to store the value 0, 
// and make another pointer which points to xp or the temporary value, depending on whether xp points to nullptr.

long cread_alt(long *xp) {
	long res = 0;
	long *p = (xp ? xp : &res);
	return *p;
}

// if you assemble it with perameter -Og, gcc will assemble it with jmp instruction;
// if you use -O1, then you'll find that the code is very long.
// But don't worry, that is because gcc detected that we used &res, which is a stack variable.
// attackers may matipulate them to distort the stack.
// in order to avoid all these attacks, gcc opens -fstac-protector-strong by defalut, and insert a "Canary value" to check if the stack will be distorted. if you would like to see the protector-free version, you can use: -O1 -fno-stack-protector.
//
// cread_alt:
// .LFB0:
//	.cfi_startproc
//	endbr6
//	movq    $0, -8(%rsp)
//	leaq    -8(%rsp), %rax
//	testq   %rdi, %rdi
//	cmove   %rax, %rdi
//	movq    (%rdi), %rax
//	ret
//	.cfi_endproc
//
// gcc even didn't move %rsp to get new stack space! that's because the adress between %rsp and %rsp - 128 is designed to be empty, 
// which is also known as "Red Zone".

long absdiff(long x, long y)
{
	long result;
	if (x < y)
		result = y - x;
	else result = x - y;
	return result;
}
/*
 * This lighter version don't consider global static variables, 
 * so the assembler should use condition move to realize the if-control.
 * but it turns out that if you use -Og, then the assembly output 
 * is still based on jump instructions, not cmov.
 * EVEN the below codes look just like what cmov operates, the compiler
 * don't intepret them as cmov instruction.
 * you should assemble it with -O1 or above.*/

long cmovdiff(long x, long y)
{
	long rval = y-x;
	long eval = x-y;
	long ntest = x>=y;
	/* Line below requires single instruction:*/
	if(ntest)rval=eval;
	return rval;
}

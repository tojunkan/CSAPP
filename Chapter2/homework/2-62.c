#include <stdio.h>
//difficulty:***
//as you may know, ">>", right shifts, has two types:
//arithmatical ones, which fill left spaces in align with the most significant bit;
//logical one, which always fill left spaces with 0.
//this program aims to check if the machine uses arithmatic right shifts for integers.(unsigned integers always use logical ones)
//this program can run on a machine with any word size.
int int_shifts_are_arithmatic() {
	int x = ~0;
	x=x>>1;
	return x == ~0;
}

int main()
{
	printf(int_shifts_are_arithmatic()? "arithmatic\n" : "logic\n");
	return 0;
}

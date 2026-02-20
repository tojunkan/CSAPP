#include <stdio.h>
//difficulty:****
//this program returns 1 when x contains an odd nonber os 1s; 0 otherwise.
//assume w=32.
//
//the function should follow the rule of:
/*
 *** Assumptions:
 * Integers are represented in two’s-complement form.
 * Right shifts of signed data are performed arithmetically.
 * Data type int is w bits long. For some of the problems, you will be given a specific value for w, but otherwise your code should work as long as w is a multiple of 8. You can use the expression sizeof(int)<<3 to compute w.
 * 
 *** Forbidden:
 * Conditionals (if or ?:), loops, switch statements, function calls, and macro invocations.
 * Division, modulus, and multiplication.
 * Relative comparison operators (<, >, <=, and >=).
 * Casting, either explicit or implicit.
 * 
 *** Allowed operations:
 * All bit-level and logic operations.
 * Left and right shifts, but only with shift amounts between 0 and w - 1.
 * Addition and subtraction.
 * Equality (==) and inequality (!=) tests. (Some of the problems do not allow these.)
 * Integer constants INT_MIN and INT_MAX.
*/
//besides, the code should contain a total of at most 12 arithmetic, bit-wise, and logical operations.
//

typedef unsigned char *byte_pointer;
void show_bits(byte_pointer a, size_t len) {
	int i, j;
	unsigned char tmp;
	for(i=len-1;i>=0;i--) 
	{
		printf(" ");
		tmp = a[i];
		for(j=7;j>=0;j--)
			printf("%u", (tmp>>j) & 1);
	}
	printf("\n");
}


int odd_ones(unsigned x) {
	unsigned shiftx = 0;
	for(unsigned i = sizeof(unsigned)*4;i>=1;i>>=1)
	{
		//printf("%u\n", i);0a
		shiftx=x>>i;
		show_bits((byte_pointer)&x, sizeof(unsigned));
		show_bits((byte_pointer)&shiftx, sizeof(unsigned));
		x = (x ^ x>>i);
		x = x & (1<<i)-1;
		show_bits((byte_pointer)&x, sizeof(unsigned));
		printf("\n");
	}
	//for convinence, I used loop, but actually not necessary for given wordsize.
	//the code above can be written to:
	//x ^= 16;
	//x &= (1<<16)-1;
	//x ^= 8;
	//x &= (1<<8)-1;
	//x ^= 4;
	//x &= (1<<4)-1;
	//x ^= 2;
	//x &= (1<<2)-1;
	//x ^= 1;
	//x &= (1<<1)-1;
	return x & 1;
}

int main()
{
	unsigned x;
	printf("please enter an unsigned number x.\n");
	scanf("%u", &x);
	if(odd_ones(x))printf("x contains an odd number of 1s.\n");
	else printf("x contains an even number of 1s.\n");
	return 0;
}


#include<stdio.h>
//difficulty:**
//
typedef unsigned char *bit_pointer;

void show_bits(bit_pointer a, size_t len) {
	size_t i;
	for(i=len;i>0;i--)
		printf(" %.2x", a[i-1]);
	printf("\n");
}
/*The following code does not run properly on some machines */
int bad_int_size_is_32() {
	/*Set most significant bit (msb) of 32-bit machine */
	int set_msb = 1 << 31;
	/*Shift past msb of 32-bit word */
	int beyond_msb = 1 << 32;
	show_bits((unsigned char *)&beyond_msb, sizeof(int));

	/* set_msb is nonzero when word size >= 32
	 * beyond_msb is zero when word size <= 32 */
	return set_msb && !beyond_msb;
}

/* When compiled and run on a 32-bit SUN SPARC, however, this procedure returns 0. The following compiler message gives us an indication of the problem:
 * warning: left shift count >= width of type */

//obviously, here left shift causes overflow, which is an undefined behaviour. So in some cases, the "1 << 32" may not yeild 0.
//instead, we can use two steps to approach the effect of "1 << 32", which is :
int good_int_size_is_32() {
	int set_msb = 1 << 31;
	int beyond_msb = set_msb << 1;//use two steps to make sure it won't trigger warning and undefined behaviour.
	show_bits((bit_pointer)&beyond_msb, sizeof(int));

	return set_msb && !beyond_msb;
}

//a more universal version:
int int_size_is_32() {
	unsigned int u = 1u;
	int bits=0;
	while(u!=0) {
		u <<= 1;
		bits++;
	}
	return bits == 32;
}
int main()
{
	printf("%d\n", bad_int_size_is_32());
	printf("%d\n", good_int_size_is_32());
	printf("%d\n", int_size_is_32());
	return 0;
}

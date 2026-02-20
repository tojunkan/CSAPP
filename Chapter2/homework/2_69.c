#include<stdio.h>
//difficulty:***
//

typedef unsigned char *byte_pointer;
void show_byte(byte_pointer a, size_t len) {
	for(size_t i=len;i>0;i--)
		printf(" %.2x", a[i-1]);
	printf("\n");
}

void show_bits(byte_pointer a, size_t len) {
	unsigned char tmp;
	for(size_t i=len;i>0;i--)
	{
		printf(" ");
		for(int j=7;j>=0;j--)
			printf("%d", (a[i-1]>>j) & 1);
	}
	printf("\n");
}

/*
 * Do rotating left shift. Assume 0 <= n < w
 * Examples when x = 0x12345678(which is 305419896) and w = 32:
 * 	n=4 -> 0x23456781, n=20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n) {
	//unsigned overflow_mask = (~0)>>((sizeof(unsigned)<<3)-n)<<((sizeof(unsigned)<<3)-n);//this will trigger warning when it comes to n=0, causing undefined behaviour that left shift count isn't smaller than width of type.
	unsigned overflow_mask = (~0)>>((sizeof(unsigned)<<3)-n-1)>>1<<((sizeof(unsigned)<<3)-n-1)<<1;
	show_byte((byte_pointer)&overflow_mask, sizeof(unsigned));
	show_bits((byte_pointer)&overflow_mask, sizeof(unsigned));
	unsigned overflow = x & overflow_mask;
	overflow = overflow >> ((sizeof(unsigned)<<3)-n-1) >> 1;
	printf("\n");
	show_byte((byte_pointer)&overflow, sizeof(unsigned));
	show_bits((byte_pointer)&overflow, sizeof(unsigned));
	x = (x<<n) + overflow;
	show_byte((byte_pointer)&x, sizeof(unsigned));
	show_bits((byte_pointer)&x, sizeof(unsigned));
	return x;
}


int main()
{
	int i, n;
	printf("please enter two numbers.\nFirst one is the number to be processed, and the second one is the digits to be left shifted.\n");
	scanf("%d%d", &i, &n);
	show_byte((byte_pointer)&i, sizeof(int));
	show_bits((byte_pointer)&i, sizeof(int));
	rotate_left(i, n);
	return 0;
}

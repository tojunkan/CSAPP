#include<stdio.h>
//difficulty:**
//
/*
 * mask with least significant n bits set to 1
 * Examples: n = 6 --> 0x3F; n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 */

typedef unsigned char *bits_pointer;
void show_bits(bits_pointer a, size_t len) {
	size_t i;
	for(int i=len;i>0;i--) {
		printf(" ");
		for(int j=7;j>=0;j--)
			printf("%d", (a[i-1]>>j) & 1);
	}
	printf("\n");
}

int lower_one_mask(int n) {
	unsigned int full = ~0;
	full >>= ((sizeof(int)>>3)-n);
	return (int)full;
}

int main()
{
	printf("please enter a number n, representing tthe least significant n bits to be masked.\n");
	int n;
	scanf("%d", &n);
	int ans = lower_one_mask(n);
	show_bits((bits_pointer)&ans, sizeof(int));
	return 0;
}

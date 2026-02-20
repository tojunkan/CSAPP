#include <stdio.h>
//dificulty:*
//this program returns 1 when any odd bit of x equals 1; 0 otherwise.
//assume w=32.

typedef unsigned char *byte_pointer;

void show_bits(byte_pointer a, size_t len) {
	int i, j;
	unsigned char tmp;
	for(i=len-1;i>=0;i--)
	{
		printf(" ");
		tmp=a[i];
		for(j=7;j>=0;j--)printf("%d", (tmp>>j) & 1);
	}
	printf("\n");
}

int any_odd_one(unsigned x) {
	unsigned mask = 0x55555555;
	return !!(x & mask);
}

int main()
{
	unsigned x;
	printf("please enter an unsigned number x.\n");
	scanf("%u", &x);
	show_bits((byte_pointer)&x, sizeof(unsigned));
	if(any_odd_one(x))printf("the number has at least one odd bit of 1.\n");
	else printf("every odd bit of x equals 0.\n");
	return 0;
}

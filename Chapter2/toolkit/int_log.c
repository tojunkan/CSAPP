#include<stdio.h>
#include"highbit.c"
#include"popcount.c"

int int_log(unsigned x) {
	int hb = high_bit_full1(x);
	hb = popcount(hb);
	return hb;
}

int main()
{
	unsigned x;
	scanf("%u", &x);
	printf("%d\n", int_log(x));
}

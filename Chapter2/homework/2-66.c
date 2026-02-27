#include <stdio.h>
//difficulty:***
//generate mask indicationg leftmost 1 in x.
//assume w=32.
//for example, 0xFF00 -> 0x8000; 0x6600 -> 0x4000
//if x == 0, then return 0.
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
			printf("%d", (tmp>>j) & 1);
	}
	printf("\n");
}

int leftmost_one(unsigned x) {
	//note: this function is also called "highbit", corresponding with the function "lowbit", althought the way to realize them are totally different.
	size_t w = sizeof(unsigned), i;
	show_bits((byte_pointer)&x, w);
	for(i=1;i<=(w*4);i<<=1)
	{
		x |= x>>i;
		//the point is, assuming x = 0...01x.... (where 1 is the left most 1.
		//using right shift to override that 1's right bits.
		//the perform "override" is completed by bit-wise OR.
		//using OR has a benefit that the left bits don't have any influence, because 0 OR x = x.
		//so after the loop, the x turn's out to be 0...011...
		show_bits((byte_pointer)&x, w);
	}

	 x -= (x >> 1);
	 //and finally remove those 1s on the right hand.
	 show_bits((byte_pointer)&x, w);
	 return (int)x;
}

int main()
{
	unsigned x;
	printf("please enter an unsigned number.\n");
	scanf("%u", &x);
	printf("the highest bit is:%d\n", leftmost_one(x));
	return 0;
}

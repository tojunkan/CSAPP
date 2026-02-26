#include<stdio.h>

int popcount(int x)
{
	//sizeof(x) = 4;
	//the key is that every bit also means the number of the 1 in the range.
	x = (x & 0x55555555) + ((x>>1) & 0x55555555);//add one by one
	//let's take an expample.
	//x			 01111100 10001110 10111010 10101010
	//0x55555555		 01010101 01010101 01010101 01010101
	//x&0x55555555		 01010100 00000100 00010000 00000000
	//
	//x>>1			  01111100 10001110 10111010 10101010
	//(x>>1)&0x55555555	 00010100 01000101 01010101 01010101
	//sum			 01101000 01001001 01100101 01010101
	//			|01| -> 1, which means now x has one 1 in this range.
	
	x = (x & 0x33333333) + ((x>>2) & 0x33333333);//added two by two
	//if you still confused about the algorithm, let's do it again.
	//x			 01101000 01001001 01100101 01010101
	//0x55555555		 00110011 00110011 00110011 00110011
	//x&0x55555555		 00100000 00000001 00100001 00010001
	//
	//x>>1			   01101000 01001001 01100101 01010101
	//(x>>1)&0x55555555	 00010010 00010010 00010001 00010001
	//sum			 00110010 00010011 00110010 00100010
	//			|0011| -> 3, which means now x has thee 1s in this range.
	x = (x & 0x0F0F0F0F) + ((x>>4) & 0x0F0F0F0F);//added four by four
	x = (x & 0x00FF00FF) + ((x>>8) & 0x00FF00FF);//added 8 by 8
	x = (x & 0x0000FFFF) + ((x>>16) & 0x0000FFFF);//added 16 by 16
	return x;
	
}

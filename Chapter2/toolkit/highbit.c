#include<stdio.h>

int high_bit(int x) {
	//sizeof(int) = 4
	x |= x>>1;//copied the highest bit to the next bit
	x |= x>>2;//copied the highest 2 bits to the next 2 bits.
	x |= x>>4;
	x |= x>>8;
	x |= x>>16;//fill all possible bits (as long as int has 32 bits).

	//until here, we get a number that bits lower than the highest has been all filled with 1.
	
	x -= x>>1;
	return x;
}

int high_bit_full1(int x) {
	x |= x>>1;
	x |= x>>2;
	x |= x>>4;
	x |= x>>8;
	x |= x>>16;
}

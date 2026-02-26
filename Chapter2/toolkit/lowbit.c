#include<stdio.h>

int low_bit(int x)
{
	return x & -x;
}

#include<stdio.h>
//difficulty: ****
//

typedef unsigned float_bits;

typedef unsigned char *byte_pointer;

float_bits f2fb(float f){return *(float_bits *)&f;}
float fb2f(float_bits f){return *(float *)&f;}

void show_bits(byte_pointer a, size_t len) {
	for(size_t i=len; i>0;i--)
	{
		//printf(" ");
		for(int j=7; j>=0;j--)
			printf("%d", (a[i-1]>>j) & 1);
	}
	printf("\n");
}

/* This program implememts the function with the flollowing prototype:*/
/* Compute (int)f. 
 * If conversion couses overflow or f is NaN, then return 0x80000000.
 * the function round towards zero. */

int bias(int x, int k) {//k ranges from 0 to w-1.
	int mask = x>>((sizeof(int)<<3)-1);
	show_bits((byte_pointer)&mask, sizeof(int));
	int b = mask & ((1<<k)-1);
	return x + b;
}

int float_f2i(float_bits f) {
	//if((f>>23 & 0xFF) >= 127+32) return 0x80000000;
	//if f is NaN, then return TMin.
      	unsigned sgn = f>>31;
	unsigned exp = f>>23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	
	int x = 0x800000 | frac;//if f is denormalized value, then it's too small.
	int E = (int)exp - 127;
	printf("sgn = %u\nexp = %u\nfrac = %u\n", sgn, exp, frac);
	
	if(E < 0) {
		x = 0;//smaller than 1.
	} else if(E <= 23) {
		x >>= 23 - E;
		for(int i=0;i<23-E;i++)printf(" ");
		show_bits((byte_pointer)&f, sizeof(float_bits));
		show_bits((byte_pointer)&x, sizeof(int));

	} else if(E <= 31) {
		x <<= E - 23;
		show_bits((byte_pointer)&f, sizeof(float_bits));
		for(int i=0;i<E-23;i++)printf(" ");
		show_bits((byte_pointer)&x, sizeof(int));
	} else x = 0x80000000;//too large. return 0x80000000.
	

	if(sgn)x = -x;
	return x;
}

int main()
{
	float x;
	printf("please enter a float number x. the program will return 0.5*x.\n");
	scanf("%f", &x);
	printf("due to the limit of precision, the number you has input was actually %f\n", x);
	int x_int = float_f2i(f2fb(x));
	printf("%d\n", x_int);
	printf("%d <- check: the true value should be\n", (int)x);
	return 0;
}

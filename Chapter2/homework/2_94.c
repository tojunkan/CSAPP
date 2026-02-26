#include<stdio.h>
//difficulty: ***
//

typedef unsigned float_bits;

typedef unsigned char *byte_pointer;

float_bits f2fb(float f){return *(float_bits *)&f;}
float fb2f(float_bits f){return *(float *)&f;}

void show_bits(byte_pointer a, size_t len) {
	for(size_t i=len; i>0;i--)
	{
	        printf(" ");
	        for(int j=7; j>=0;j--)
	                printf("%d", (a[i-1]>>j) & 1);
	}
	printf("\n");
}

/* This program implememts the function with the flollowing prototype:*/
/* Compute 0.5*f. If f is NaN, then return f. */
float_bits float_half(float_bits f) {
	if((f>>23 & 0xFF) == 0xFF) return f;
	//both inf and NaN will return themselves.
	
      	unsigned sgn = f>>31;
	unsigned exp = f>>23 & 0xFF;
	unsigned frac = f & 0x7FFFFF;
	unsigned rounding;//the half of a value may cause rounding.

	if(exp == 0) {
		rounding = frac & 1;
		frac = frac>>1;
		frac = frac + (rounding & (frac & 1));
	} else if (exp == 1) {
		exp = 0;
		rounding = frac & 1;
		frac = 1 << 22 | frac >> 1;
		frac = frac + (rounding & (frac & 1));
		exp = frac & 0x800000;
		frac = frac & 0x7FFFFF;
	}else {
		exp -= 1;
	}
	printf("sgn = %u\nexp = %u\nfrac = %u\n", sgn, exp, frac);
	unsigned u = sgn << 31 | exp << 23 | frac;
	return u;
}

int main()
{
	float x;
	printf("please enter a float number x. the program will return 0.5*x.\n");
	scanf("%f", &x);
	printf("due to the limit of precision, the number you has input was actually %f\n", x);
	float_bits x_half = float_half(f2fb(x));
	show_bits((byte_pointer)&x_half, sizeof(float_bits));
	printf("%.10f\n", fb2f(x_half));
	printf("%.10f <- the true value should be\n", x*0.5);
	return 0;
}

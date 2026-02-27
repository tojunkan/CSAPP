#include<stdio.h>
//difficulty: *

typedef unsigned char *byte_pointer;
void show_byte(byte_pointer a, size_t len) {
	for(size_t i=len;i>0;i--) {
		printf(" ");
		for(int j=7;j>=0;j--)
			printf("%d", (a[i-1]>>j) & 1);
	}
	printf("\n");
}

void show_float(float *num) {
        show_byte((byte_pointer) num, sizeof(float));
}

void show_unsigned(unsigned *num) {
	show_byte((byte_pointer) num, sizeof(unsigned));
}

float u2f(unsigned num) {
	return *(float *)&num;
}

/* this program is to write a C function to compute a floating-point representation of 2^x, 
 * by constructing the IEEE single-precision representation of the result.
 * when x is too small, the routine will return 0.0.
 * when x is too large, it will return +inf.*/

float fpwr2(int x)
{
	/* Result exponent and fraction */
	unsigned exp, frac;
	unsigned u;
	if (x < -149) { //the exponent range for float is -126~127.
			//frac has 23 bits, so the smallest x is -149.
		/* Too small. Return 0.0 */
		exp = 0;
		frac = 0;
		printf("Error: too small.\n");
	} else if (x < -126) {
		/* Denormalized result */
		exp = 0;
		frac = 1<< (x + 149);
	} else if (x < 128) {
		/* Normalized result. */
		exp = x + 127;
		frac = 0;
	} else {
		/* Too big. Return +oo */
		exp = 255;
		frac = 0;
	}

	/* Pack exp and frac into 32 bits */
	
	printf("exp = %u\nfrac = %u\n", exp, frac);
	u = exp << 23 | frac;
	show_unsigned(&u);

	/* Return as float */
	return u2f(u);
}

int main()
{
	int x;
	printf("please enter a number for the exponent x.\n");
	scanf("%d", &x);
	float pwr2 = fpwr2(x);
	show_float(&pwr2);
	printf("%g\n", pwr2);
	return 0;
}

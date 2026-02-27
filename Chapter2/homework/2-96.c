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
		printf(" ");
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
int low_bit(int x){
        unsigned lb = x;
        //-x = ~x+1;
        //so only the low_bit will turn back to the same as x.
        lb |= lb>>1;
        lb |= lb>>2;
        lb |= lb>>4;
        lb |= lb>>8;                                                             lb |= lb>>16;

        lb = (lb & 0x55555555) + ((lb >> 1) & 0x55555555);
        lb = (lb & 0x33333333) + ((lb >> 2) & 0x33333333);
        lb = (lb & 0x0F0F0F0F) + ((lb >> 4) & 0x0F0F0F0F);
        lb = (lb & 0x00FF00FF) + ((lb >> 8) & 0x00FF00FF);
        lb = (lb & 0x0000FFFF) + ((lb >>16) & 0x0000FFFF);
        return (int)lb;
}

float_bits float_i2f(int x) {
	//if((f>>23 & 0xFF) >= 127+32) return 0x80000000;
	//if f is NaN, then return TMin.
      	unsigned sgn = x>>31 & 1;
	if(sgn)x = -x;//x = abs(x)
	unsigned exp = low_bit(x);
	unsigned frac;
	printf("highest bit is:%u\n", exp);
	unsigned rounding = 0;
	if(exp > 23)
	{
		frac = x>>exp-23-1;
		frac &= 0x7FFFFF;
		rounding = x & ((1<<(exp-23-1))-1);
		show_bits((byte_pointer)&frac, sizeof(unsigned));
		if(rounding >= (1<<(exp-23-1-1)))
		{
			frac += 1;
			if(frac>>23 != 0)
			{
				printf("carried.\n");
				exp+=1;
				frac &= 0x7FFFFF;
			}
		}
	}
	else frac = x<<23-exp+1;//here has difference of 1 bit.
				//that's because the frac always leave out the first 1.
	

	frac &= 0x7FFFFF;
	
	exp += 126;//low_bit gives out 1~32, not 0~31.

	sgn <<= 31;
	exp <<= 23;
	show_bits((byte_pointer)&sgn, sizeof(unsigned));
	show_bits((byte_pointer)&exp, sizeof(unsigned));
	show_bits((byte_pointer)&frac, sizeof(unsigned));
	unsigned f = sgn | exp | frac;
	return f;
}

int main()
{
	int x;
	printf("please enter a int number x. the program will return (float)x.\n");
	scanf("%d", &x);
	show_bits((byte_pointer)&x, sizeof(int));
	printf("due to the limit of precision, the number you has input should be: %f\n", (float)x);
	float x_float = fb2f(float_i2f(x));
	printf("%f\n", x_float);
	printf("%f <- check: the true value should be\n", (float)x);
	return 0;
}

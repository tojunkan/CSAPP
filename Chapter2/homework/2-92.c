#include<stdio.h>
//difficulty: **
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
/* Compute |f|. If f is NaN, then return f. */
float_bits float_absval(float_bits f) {
        if(     ((f>>23 & 0xFF) == 0xFF) &&
                (f & 0x7FFFFF != 0)) return f;
        return ~(~f | 0x80000000);
}

int main()
{
        float x;
        printf("please enter a float number x. the program will return |x|.\n");
        scanf("%f", &x);
	printf("due to the limit of precision, the number you have input is %f\n", x);
        float_bits absx = float_absval(f2fb(x));
        show_bits((byte_pointer)&absx, sizeof(float_bits));
        printf("%f\n", fb2f(absx));
        return 0;
}

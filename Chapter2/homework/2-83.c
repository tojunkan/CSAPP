#include<stdio.h>
//difficulty:*
//

typedef unsigned char *byte_pointer;
void show_byte(byte_pointer a, size_t len) {
        for(size_t i=len;i>0;i--)
                printf(" %.2x", a[i-1]);
        printf("\n");
}

void show_bits(byte_pointer a, size_t len) {
        unsigned char tmp;
        for(size_t i=len;i>0;i--)
        {
                printf(" ");
                for(int j=7;j>=0;j--)
                        printf("%d", (a[i-1]>>j) & 1);
        }
        printf("\n");
}

/* fill in the return value for the following procedure, 
 * which tests whether its first argument is less than or equal to its second.
 * assume the function f2u returns an unsigned 32-bit number having the same bit representation as its floating-point argument.
 * assume that neither argument is NaN.
 * the two flavors of zero, +0 and -0, are considered equal.
 * */
unsigned f2u(float x){return *(unsigned*)&x;}
//notice that (unsigned)x will not work properly.
//the casting function is not we want that read the piece of memory as an unsigned number, 
//but rather read the value of the float and cast it to unsigend.
//for example, 	(unsigned)0.5f = 0
//		(unsigned)-3.5f = 0xFFFFFFFD(which is -3) (if the machine use 2's complement to express negative numbers)

int float_le(float x, float y) {
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);

	/* Get the sign bits */
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;
	
	//let's take a review at the expression of float.
	//the highest bit is for sign, 
	//next eight bits is for the exp, or E. 
	//	E = 0 means it's a denormalized number;
	//	E = 255 means it's an infinite number or NaN;
	//	otherwise it's a normalized number.
	//last 23 bits is for frac, a number between 0 and 1.
	//
	//for normalized nubmers, val = (-1)^sgn * 2^(E-bias) * (1+frac)
	//	where bias = 2^(8-1)-1.
	//for denormalized numbers, val = (-1)^sgn * 2^(1-bias) * frac
	//for the third type, if frac is not 0 then it's NaN.
	//
	//so, one interesting property of this representation is that
	//if we intepret the bit representations of the values as unsigned integers,
	//they occur in ascending order, 
	//as do the values they represent as floating-point numbers.
	//of course, negative numbers occurs in descending order because they have a leading 1.
	//
	return ((ux<<1) == 0 && (uy<<1) == 0) || //x and y are both zeros
		(sx && !sy) || //x is negative while y is positive
		(!sx && !sy && ux <= uy) || //x > 0 and y > 0
		(sy && sx && ux >= uy) //x < 0 and y < 0
		;
}
int main()
{
        float x, y;
        printf("Please enter two float numbers x and y. the program will return 1 if x is not larger than y.\n");
        scanf("%f%f", &x, &y);
        show_byte((byte_pointer)&x, sizeof(float));
        show_bits((byte_pointer)&x, sizeof(float));
        show_byte((byte_pointer)&y, sizeof(float));
        show_bits((byte_pointer)&y, sizeof(float));
	printf("%d\n", float_le(x, y));
        return 0;
}

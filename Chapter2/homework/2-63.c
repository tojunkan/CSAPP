#include <stdio.h>
//difficulty:***
//function "srl" performs a logical right shift using an arithmetic right shift (given by value "xsra"), followed by other operations not including right shifts or division.
//function "sra" performs an arithmetic right shift using a logical right shift (given by value "xsrl"), followed by other operations not including right shifts or division.
//You may use the computation "8*sizeof(int)"to determine w, the number of bits in data type "int".
//The shift amount "k" can range from 0 to "w-1".
//
typedef unsigned char *byte_pointer;
void show_byte(byte_pointer a, size_t len) {
        int i;
        for(i=len-1;i>=0;i--)
                printf(" %.2x", a[i]);
        printf("\n");
}
void show_bits(byte_pointer a, size_t len) {
	int i, j;
	unsigned char tmp;
	for(int i=len-1;i>=0;i--)
	{
		printf(" ");
		tmp=a[i];
		for(j=7;j>=0;j--)
			printf("%d", (tmp>>j)&1);
	}
	printf("\n");
}

unsigned srl(unsigned x, int k) {
	/* Perform shift arithmetically */
	size_t w = sizeof(unsigned);
	show_bits((byte_pointer)&x, w);
	unsigned xsra = (int) x >> k;
	show_bits((byte_pointer)&xsra, w);
	unsigned operator = (1<<8*w-k)-1;
	//note that if k == 0, then the left shift will give out 0x0,
	//0x0u = 0x1 + 0xFFFFFFFF, which means 0xFFFFFFFF=0-1 in unsigned version. 0xFFFFFFFF is the inverse of 0x1.
	show_bits((byte_pointer)&operator, w);

	xsra = xsra  & operator;
	show_bits((byte_pointer)&xsra, w);
	return xsra;
}

int sra(int x, int k) {
	/* Perform shift logically */
	size_t w = sizeof(int);
	show_bits((byte_pointer)&x, w);
	int xsrl = (unsigned) x >> k;
	show_bits((byte_pointer)&xsrl, w);
	unsigned operator = (1<<8*w-k)-1;
	//note: here operator generated a binary number that higest k digits are 0 while others are 1.
	//for example, if xsrl=00100110 
	//where k = 2(totally 8 digits for demo)
	//then here operator = 00111111
	unsigned sign = 1<<8*w-(k+1);
	//the arithmatical right shifts should fill left spaces in align with the highest digit, so there's a variable sign to grab this feature.
	//continued from the example,here sign was first left shifted to the highest digit. here sign = 00100000
	sign = xsrl & sign;
	//then process an AND calculation to grab the highest digit.
	//		sign = 00100000 because xsrl remains 1 at the according location.
	sign = !(!sign);
	//then use logical NOT to get the same effect of right shift
	//		sign = 00000001
	sign = 0u - sign;
	//here's the trick: use 0 minus sign gives out a mask:
	//if sign == 0, then output should be:
	//		sign = 00000000
	//else if sign == 1, then output should be:
	//		sign = 11111111
	operator = (~operator) & sign;
	//so that we can use this mask to adjust operator so that it turns out to be aligned with the highest digit.
	//	    operator = 11000000
	show_bits((byte_pointer)&operator, w);
	show_bits((byte_pointer)&sign, w);
	show_bits((byte_pointer)&operator, w);

	xsrl = xsrl  | operator;
	//and finally use bitwise OR to bond the arithmatical replacement.
	show_bits((byte_pointer)&xsrl, w);
	return xsrl;
}

int main()
{
	unsigned xunsigned;
	int k, xint;
	printf("enter an unsigned number x and an integer (0~31) k.\n");
	scanf("%u%d", &xunsigned, &k);
	xunsigned = srl(xunsigned, k);
	printf("the logicall right shift version of unsigned integer is:%u\n", xunsigned);

	printf("enter an unsigned number x and an integer (0~31) k.\n");
	scanf("%d%d", &xint, &k);
	xint = sra(xint, k);
	printf("the logicall right shift version of unsigned integer is:%u\n", xint);
	return 0;
}

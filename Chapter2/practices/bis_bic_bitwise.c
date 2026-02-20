#include <stdio.h>

int bis(int x, int m) {
	return x | m;
}
//notice:"bis" refers to "bits set", which means a function that sets spacific bits to 1.
//the number m gives the location of x that should be set to 1, for example:
//x	=	1010
//m	=	1100
//bis(x,m)=	1110
//the corresponding place where m is 1 should be set to 1 in the output, while places where 0 remains the original x value.
//as you can see in the example, the effect remains equivalent to the function "or".
int bic(int x, int m) {
	return x & (~m);
}

//notice:"bic" refers to "bits clear", which means a function that sets spacific bits to 0.
//the number m gives the location of x that should be set to 1, for example:
//x	=	1010
//m	=	1100
//bis(x,m)=	0010
//the corresponding place where m is 1 should be set to 0 in the output, while places where 0 remains the original x value.
//as you can see in the example, the effect remains equivalent to the function x&(~m).
int bool_or(int x, int y) {
	return bis(x, y);
}

int bool_and(int x, int y) {
	return bic(x, ~y);
}

int bool_xor(int x, int y) {
	return bis(bic(x, y), bic(y, x));
}
//notice:you can simply use function bis and bic to realize xor.
//an interesting phenomenon is that xor is commutative, whereas function bic is not commutative:
//x	=	1010
//m	=	1100
//bis(x,m)=	0010
//bis(m,x)=	0100
void print(int x) {
	for(int i=0;i<32;i++, x=x<<1)
		printf(" %d", (x & 0x80000000)>>31);
}

int main()
{
	int n, m;
	printf("please enter two decimal numbers.\n");
	scanf("%d%d", &n, &m);
	printf("\n\nthe number in binary scale is:n=\t");
	print(n);
	printf("\n\nwhile m=\t\t\t\t");
	print(m);

	printf("\n\nthe result of bis(n, m)=\t\t");
	print(bis(n, m));

	printf("\n\nthe result of bic(n, m)=\t\t");
	print(bic(n, m));

	printf("\n\nthe result of bic(m, n)=\t\t");
	print(bic(m, n));

	printf("\n\nthe result of or(n, m)=\t\t\t");
	print(bool_or(n, m));

	printf("\n\nthe result of and(n, m)=\t\t");
	print(bool_and(n, m));

	printf("\n\nthe result of xor(n, m)=\t\t");
	print(bool_xor(n, m));
	printf("\n");
	return 0;
}


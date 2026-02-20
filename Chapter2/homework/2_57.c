#include <stdio.h>
//difficulty:*
typedef unsigned char *byte_pointer;

void show_byte(byte_pointer a, size_t len) {
	int i;
	for(i=0;i<len;i++)
		printf(" %.2x", a[i]);
	printf("\n");
}

void show_double(double *num) {
	show_byte((byte_pointer) num, sizeof(double));
}
void show_short(short *num) {
	show_byte((byte_pointer) num, sizeof(short));
}
void show_long(long *num) {
	show_byte((byte_pointer) num, sizeof(long));
}
int main()
{
	printf("Please enter three numbers:\nfirst one should be a decimal;\nsecond one should be a short integer(-32768~32767);\nand the third one can be a long integer(-2^63~2^62-1).\n");
	double a;
	short b;
	long c;
	scanf("%lf%hd%ld", &a, &b, &c);
	show_double(&a);
	show_short(&b);
	show_long(&c);
	return 0;
}

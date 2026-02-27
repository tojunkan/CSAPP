#include <stdio.h>
//difficulty:**
//this program tries to paste one number's lowest byte to another number.
//
typedef unsigned char *byte_pointer;
void show_byte(byte_pointer a, size_t len) {
        int i;
        for(i=len-1;i>=0;i--)
                printf(" %.2x", a[i]);
        printf("\n");
}

long paste(long a, long b) {
	printf("step 1:shift b \nfrom\t");
	show_byte((byte_pointer)&b, sizeof(long));
	b = (b >> 8) << 8;
	printf("to\t");
	show_byte((byte_pointer)&b, sizeof(long));
	
	printf("step 2: wipe out a except the lowest byte\nfrom\t");
	show_byte((byte_pointer)&a, sizeof(long));
	a = a & 0xFF;
	printf("to\t");
	show_byte((byte_pointer)&a, sizeof(long));
	
	long ans = b | a;
	//here should use or(or xor) to bond two numbers
	//not plus, because plus may have the problem of carrying.
	printf("step 3: bond processed b and a, returning\n\t");
	show_byte((byte_pointer)&ans, sizeof(long));
	return ans;
}
int main()
{
	long a, b;
	scanf("%ld%ld", &a, &b);
	long ans = paste(a, b);
	return 0;
}

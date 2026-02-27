#include<stdio.h>
//difficulty:**
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

/*
 * Return 1 when x can be represented as an n-bit, 2's complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 */
int fits_bits(int x, int n) {
	printf("%d\t%u\n", n, (~0u)>>n);
	int mask = (int)(~((~0u)>>((sizeof(unsigned)<<3)-n)));
	show_byte((byte_pointer)&mask, sizeof(int));
	show_bits((byte_pointer)&mask, sizeof(int));
	return !(mask & x);
}
int main()
{
        int i, n;
	printf("please enter two numbers, first one is the number to be checked, and the second one is for n digits.\n");
	scanf("%d%d", &i, &n);
        show_byte((byte_pointer)&i, sizeof(int));
        show_bits((byte_pointer)&i, sizeof(int));
	if(fits_bits(i, n))printf("YES\n");
	else printf("NO\n");
        return 0;
}

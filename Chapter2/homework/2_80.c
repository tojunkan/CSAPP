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
/* Write C expressions to generate the bit patterens that follow:
 * A:1^(w-k)*0^k;
 * B:0^(w-k-j)*1^k*0^j, 
 * where a^k represents k repetitions of symbol a.
 * Assume a w-bit data type.
 * The code may contain references to parameters j and k, representing the values of j and k, but not a parameter representing w.*/
int mask_generate(int k, int j) {
	if(k + j >= sizeof(int)<<3)return -1;
	int step1 = -1 << k;
	show_bits((byte_pointer)&step1, sizeof(int));
	int step2 = (~step1) << j;
	show_bits((byte_pointer)&step2, sizeof(int));
	return step2;
}
int main()
{
        int x, y;
        printf("Please enter two numbers k and j. the program will generate a specific pattern for you.\n");
        scanf("%d%d", &x, &y);
        //show_byte((byte_pointer)&x, sizeof(int));
        //show_bits((byte_pointer)&x, sizeof(int));
        //show_byte((byte_pointer)&y, sizeof(int));
        //show_bits((byte_pointer)&y, sizeof(int));
        mask_generate(x, y);
	return 0;
}

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

/*
 * You just started working for a company that is implementing a set of procedures to operate on a data structure where 4 signed bytes are packed into a 34-bit unsigned.
 * Bytes within the word are numbered from 0 (least signifanct) to 3 (most significant).
 * You have binn assigned the task of implementing a function for a machine using two's-complement arithmetic right shifts with the following prototype:
 */
/* Declarationg of data type where 4 bytes are packed into an unsigned*/
typedef unsigned packed_t;

/* Extract byte from word. Return as signed integer 
 * That is, the function will extract the designated byte and sign extend it to be a 32-bit int.*/

int xbyte(packed_t word, int bytenum)
{
	/*return (word >> (bytenum << 3)) & 0xFF;this function failed attempt at xbyte, because the value wanted is a signed value.so the sign bit could turn wrong when it comes to negative numbers */
	return ((int)(word << ((3 - bytenum) << 3))) >> 24;
}

int main()
{
        unsigned word;
	int n;
	printf("Please enter two numbers, one for the whole data set, and one for the bytenum.\n");
	scanf("%u%d", &word, &n);
        show_byte((byte_pointer)&word, sizeof(unsigned));
        show_bits((byte_pointer)&word, sizeof(unsigned));
	
	int ans = xbyte(word, n);
	printf("%d\n", ans);	
	show_bits((byte_pointer)&ans, sizeof(int));
        return 0;
}

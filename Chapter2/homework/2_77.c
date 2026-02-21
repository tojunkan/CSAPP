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

/* write code for a cunftion with the following prototype:*/
/* Divide by power of two.  Assume 0 <= k < w-1 */
int divide_power2(int x, int k);
/* the function should compute x/2^k with correct rounding, and it should follow the bit-level integer colding rules.*/
int bias(int x, int k) {
	//the key is to get the correct biased value for negatives.
	int mask = (x&0x80000000);
	mask -= !!mask;//since the largest value of k is up to 31, we can left the most significant bit to 0.
	//show_bits((byte_pointer)&mask, sizeof(int));
	int biasing = (1<<k)-1;//the operator "-" is prior to operator "<<"
	//show_bits((byte_pointer)&biasing, sizeof(int));
	biasing &= mask;
	//show_bits((byte_pointer)&biasing, sizeof(int));
	return biasing;
}
int divide_power2(int x, int k) {
	int b = bias(x, k);
	return (x+b)>>k;
}
int main()
{
        int x, y;
        printf("Please enter two numbers x and k. the program will return x divided by 2 to the power of k.\n");
        scanf("%d%d", &x, &y);
        show_byte((byte_pointer)&x, sizeof(int));
        show_bits((byte_pointer)&x, sizeof(int));
        show_byte((byte_pointer)&y, sizeof(int));
        show_bits((byte_pointer)&y, sizeof(int));

	printf("the answer is:%d\n", divide_power2(x, y));
	return 0;
}

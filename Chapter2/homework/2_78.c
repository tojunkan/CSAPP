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
/* write code for a function mul3div4 that, 
 * for integer argument x, computes 3*x/4, but following the bit-level integer coding rules.
 * the code should replicate the fact that the computation 3*x can cause overflow.*/
int bias(int x, int k) {
        //the key is to get the correct biased value for negatives.
        int mask = (x&0x80000000);
        mask -= !!mask;//since the largest value of k is up to 31, we can left the most significant bit to 0.
        int biasing = (1<<k)-1;//the operator "-" is prior to operator "<<"
        biasing &= mask;
        return biasing;
}
//here copied the function bias in the question 2_77.
int mul3div4(int x) {
	int x3 = x+(x<<1);
	int biased = bias(x3, 2);
	return x3 + bias(x3, 2)>>2;
}
int main()
{
        int x, y;
        printf("Please enter a number x. the program will return x times 3 then divided by 4.\n");
        scanf("%d", &x);
        show_byte((byte_pointer)&x, sizeof(int));
        show_bits((byte_pointer)&x, sizeof(int));
        printf("the answer is:%d\n", mul3div4(x));
	return 0;
}

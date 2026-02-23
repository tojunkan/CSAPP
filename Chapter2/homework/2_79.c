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
/*write code for a function threeforths which,
 * for integer argument x, computes the value of (3/4)*x, rounded toward zero.
 * it should not overflow.
 * the function should follow the bit-level integer coding rules.*/
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
        int x_4 = x + bias(x, 2)>>2;
        //return x_4 + (x_4<<1);writing like this is not perfect.
	//because the rounding process is happend when doing division, not after whole calculation. the remainder (or modulus) hasn't been take to account.
	int remainder = x - (x_4<<2);//calculate remainder
				     //another writing is x & 0x3.
	x_4 += (x_4<<1);
	//show_bits((byte_pointer)&remainder, sizeof(int));
	remainder = remainder + (remainder<<1);
	//for the remainder, the calculation can be reversed:
	//we can first calculate remainder * 3
	remainder = (remainder + bias(remainder, 2))>>2;//and then calculate it divided by 4.
	//printf("%d\n%d\n", remainder, remainder + x_4);
	return remainder + x_4; 
}
int main()
{
        int x, y;
        printf("Please enter a number x. the program will return x times 3 then divided by 4.\nInstead of the program 2_78, this program won't cause overflow.\n");
        scanf("%d", &x);
        show_byte((byte_pointer)&x, sizeof(int));
        show_bits((byte_pointer)&x, sizeof(int));
        printf("the answer is:%d\n", mul3div4(x));
        return 0;
}

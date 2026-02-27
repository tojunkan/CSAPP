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
int w = sizeof(int);

/*Addition that saturates to TMin or TMax*/
int saturating_add(int x, int y) {
	int xsgn = x>>((w<<3)-1);
	int ysgn = y>>((w<<3)-1);

	int ans = x + y;
        show_byte((byte_pointer)&ans, w);
        show_bits((byte_pointer)&ans, w);
	
	int asgn = ans>>((w<<3)-1);

	//the overflow only occurs when xsgn == ysgn != asgn
	//int of = (!xsgn ^ ysgn) & (ysgn ^ asgn);
	//here the definitiion of "of" is buggy, because the xsgn and ysgn could be negative, then right shift is not completely inserting 0 on the left. so here needs some tricks:
	xsgn = !!xsgn;
	ysgn = !!ysgn;
	asgn = !!asgn;
	int of = (!xsgn ^ ysgn) & (ysgn ^ asgn);
	printf("overflow value:%d\n", of);
	of = !!of;
	if(of)printf("Overflow has occurred.\n");
	else printf("No overflow has occurred.\n");
	//note that in unsigned field, TMin - 1 == TMax, 
	//so we can distinguish positive overflow from negative ones.
	//another problem is, how to generate such a mask.
	//int mask = (of<<((w<<3)-1)) - 1 + of;
	//here seems to be alright, but left shift may become TMin, and
	//TMin - 1 is undefined.
	int mask = (of<<((w<<3)-1)) + of - 1;
	printf("mask:\n");
        show_byte((byte_pointer)&mask, w);
        show_bits((byte_pointer)&mask, w);
	ans &= mask;
	printf("step 1:\n");
	show_byte((byte_pointer)&ans, w);
        show_bits((byte_pointer)&ans, w);
	ans |= of<<((w<<3)-1);
	printf("step 2:\n");
	show_byte((byte_pointer)&ans, w);
        show_bits((byte_pointer)&ans, w);
	ans = ans - (!xsgn & of);
	printf("operator: %d\nstep 3:\n", (!xsgn & of));
	show_byte((byte_pointer)&ans, w);
        show_bits((byte_pointer)&ans, w);
	return ans;
}
int main()
{
        int x, y;
	printf("Please enter two numbers. the program will give you the saturating added answer.\n");
	scanf("%d%d", &x, &y);
        show_byte((byte_pointer)&x, w);
        show_bits((byte_pointer)&x, w);
        show_byte((byte_pointer)&y, w);
        show_bits((byte_pointer)&y, w);
	int ans = saturating_add(x, y);
        printf("%d\n", ans);
	return 0;

}

#include <stdio.h>
//difficulty:**
//this program tries to validate an integer, the following conditions will yeild 1 while any other circumstances yeild 0.
//A. any bit of x equals 1
//B. any bit of x equals 0
//C. any bit in the least significant byte of x equals 1
//D. any bit in the most significant byte of x equals 0
//
typedef unsigned char *byte_pointer;
void show_byte(byte_pointer a, size_t len) {
        int i;
        for(i=(int)len-1;i>=0;i--)
                printf(" %.2x", a[i]);
        printf("\n");
}

int validate(int x) {
	return  !(x ^ 0xFFFFFFFF) ? 1 :
		!(x ^ 0x00000000) ? 2 :
		(x & 0x000000FF) ? 3 :
		(~x & 0xFF000000) ? 4 : 0;
	//0xFFFFFFFF=-1
	//0x00000000=0
	//0x000000FF=255
	//0xFF000000=-16777216
}

int main()
{
	int x, ans;
	scanf("%d", &x);
	show_byte((byte_pointer)&x, sizeof(int));
	ans = validate(x);
	if(ans==1)printf("A\n");
	else if(ans==2)printf("B\n");
	else if(ans==3)printf("C\n");
	else if(ans==4)printf("D\n");	
	else printf("Invalidate\n");
}

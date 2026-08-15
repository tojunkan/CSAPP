#include <stdio.h>

int howManyBits(int x) {
        int mask, mask1, mask2, mask4, mask8, mask16, highbit, ppcnt, ans;
	printf("%d\thex:%#x\n", x, x);
        x = x ^ (x>>31);
	
        highbit = x | (x>>1);
        highbit |= (highbit>> 2);
        highbit |= (highbit>> 4);
        highbit |= (highbit>> 8);
        highbit |= (highbit>>16);
        //the number of "1"s in highbit is the floor of log(|x|).
	printf("highbit:%#x\n", highbit);

        mask1 = 0x55;
	mask1 += mask1<<8;
        mask1 += mask1<<16;

        mask2 = 0x33;
        mask2 += mask2<<8;
        mask2 += mask2<<16;

        mask4 = 0x0f;
        mask4 += mask4<<8;
        mask4 += mask4<<16;

        mask8 = 0xff;
        mask8 += mask8<<16;

        mask16 = 0xff;
        mask16 += mask16<<8;
	printf("%#x\n%#x\n%#x\n%#x\n%#x\n", mask1, mask2, mask4, mask8, mask16);

        ppcnt = (highbit & mask1 ) + ((highbit>> 1) & mask1 );
        ppcnt = (ppcnt & mask2 ) + ((ppcnt>> 2) & mask2 );
        ppcnt = (ppcnt & mask4 ) + ((ppcnt>> 4) & mask4 );
        ppcnt = (ppcnt & mask8 ) + ((ppcnt>> 8) & mask8 );
        ppcnt = (ppcnt & mask16) + ((ppcnt>>16) & mask16);
	printf("popcount:%d\n", ppcnt);

        ans = ppcnt + 1;
        return ans;
}

int main() {
	int a;
	while(scanf("%d", &a)) {
		printf("%d\n", howManyBits(a));
	}
	return 0;
}

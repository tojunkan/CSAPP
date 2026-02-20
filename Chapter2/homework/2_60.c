#ainclude <stdio.h>
#include <inttypes.h>
//difficulty:**
//this program tries to replace a byte of a number.
//gives in three arguments:
//x refers to the number to be processed;
//i refers to the index of the byte(0-7);
//b refers to the replacement byte.
//

typedef unsigned char *byte_pointer;
void show_byte(byte_pointer a, size_t len) {
        int i;
        for(i=(int)len-1;i>=0;i--)
                printf(" %.2x", a[i]);
        printf("\n");
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
	printf("step 0: original number x=%u:\n\t", x);
	show_byte((byte_pointer)&x, sizeof(unsigned));

	unsigned replacement = 0xFF;
	i=i<<3;
	//printf("%d\n", i);
	replacement = ~(replacement << i);
	printf("step 1: locate the byte that needs to change:\n\t");
	show_byte((byte_pointer)&replacement, sizeof(unsigned));
	
	x = x & replacement;
	printf("step 2: wipe the according location out:\n\t");
	show_byte((byte_pointer)&x, sizeof(unsigned));

	replacement = (unsigned)b << i;
	printf("step 3: construct the replacement:\n\t");
	show_byte((byte_pointer)&replacement, sizeof(unsigned));

	unsigned ans = x | replacement;
	printf("step 4: plus to give the final answer.\n\t");
	show_byte((byte_pointer)&ans, sizeof(unsigned));

	return ans;
}

int main()
{
	unsigned a;
	int ind;
	unsigned char rep;
	scanf("%u%d%hhu", &a, &ind, &rep);
	replace_byte(a, ind, rep);
}

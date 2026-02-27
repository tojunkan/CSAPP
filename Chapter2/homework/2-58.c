#include <stdio.h>
//difficulty:**
typedef unsigned char *byte_pointer;
void show_byte(byte_pointer a, size_t len) {
        int i;
        for(i=0;i<len;i++)
                printf(" %.2x", a[i]);
        printf("\n");
}

int check_endianness() {
	//this function return true if the program was run on a small endian computer.
	//to make this function capable to 32bits and 64bits systems, the a should not set to a spacific value.
	//although actually, the type "unsigned" remains the same length in both 32 and 64 bits.
	unsigned a=(~0)-1;
	//printf("%x\n", a);
	show_byte((unsigned char *)&a, sizeof(unsigned));
	unsigned char *p = (unsigned char *)&a;
	if(*p==0xFE)return 1;
	else return 0;
}

int main()
{
	printf(check_endianness() ? "small endian computer\n" : "big endian computer\n");
	return 0;
}

#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;
//notice:typedef means that giving a type a nickname.
//here means giving type "unsigned char *" another name byte_pointer,
//which means every address that it points to will be intepreted as a character with only one byte, not the type it actually is.
//for example, 0x111 to 0x114 store an integer 12345, which is 0x00 00 30 39, but if the program visits that space with byte_pointer, the value in 0x111 will be intepreted as 00, not 12345.

void show_bytes(byte_pointer start, size_t len) {
	size_t i;
	//size_t is a type whose size changes according to the word size of the system. It's the same size as "unsigned int" (4 bytes) in 32bit system, while be the same as "unsigned long" (8 bytes) in 64bit system.
	for(i=0;i<len;i++)
		printf(" %.2x", start[i]);
	//%x means print with hex, while .2 means print at least two digits.
	//the mark "name[number]" is same as "*(name + number)".
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}


void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
	int ival = val;
	float fval = (float) val;
	int *pval = &val;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}

int main()
{
	int val;
	scanf("%d", &val);
	test_show_bytes(val);
	char *s = "abcdef";
	//show_bytes((byte_pointer) s, strlen(s));
	//show_bytes((byte_pointer) s, strlen(s)+1);
	return 0;
}

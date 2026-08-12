#include <stdio.h>
//difficulty:**

typedef enum {POS, ZERO, NEG, OTHER} range_t;

range_t find_range(float x) {
	range_t result;
	double dummy;

	__asm__ volatile (
		"vxorps %1, %1, %1\n\t"	//flush %1 to zero.
		"vucomiss %1, %2\n\t"	//compare %2(input) and 0
		"cmova %3, %0\n\t"	//move 0(POS)   to result if CF is set to 1 (NaN or positive numbers)
		"cmove %4, %0\n\t"	//move 1(ZERO)  to result if ZF is set to 1 (NaN or zero)
		"cmovb %5, %0\n\t"	//move 2(NEG)   to result if both CF and ZF are 0 (negative numbers)
		"cmovp %6, %0\n\t"	//move 3(OTHER) to result if PF is set to 1 (NaN only)
					// so that if x is NaN, result will be override to OTHER. 

		:"=r"(result)		//output variables and registers
		:"x"(dummy), "x"(x), "r"(0), "r"(1), "r"(2), "r"(3)	
					//input variables and registers
		:"cc"			//this asm code block may influence Conditional Code.
		
	);
	return result;
}

int main() {
	float num;
	scanf("%f", &num);

	//int a = 0xfff00000;
	//num = *(float *)&a;
	printf("%f\n", num);
	
	range_t res = find_range(num);

	switch(res) {

		case POS:printf("positive.\n");break;
		case ZERO:printf("zero.\n");break;
		case NEG:printf("negative.\n");break;
		case OTHER:printf("not a number.\n");break;
	};
	return 0;
}

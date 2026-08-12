#include <stdio.h>
//difficulty:*

typedef enum {POS, ZERO, NEG, OTHER} range_t;

range_t find_range(float x) {
	range_t result;
	double dummy;

	__asm__ volatile (
		"vxorps %1, %1, %1\n\t"	//flush %1 to zero.
		"vucomiss %1, %2\n\t"	//compare %2(input) and 0
		"jp 3f\n\t"		//jump if parity flag is set (which means x is NaN)
					//this should be firstly judged, or will mistakenly jumped to other branch
						//NaN will set CF PF ZF to 1 simultaneously.

		"ja 0f\n\t"		//jump if above
		"je 1f\n\t"		//jump if equal
		"jb 2f\n\t"		//jump if below

		"0:\n\t"		//use local number label, instead of global letter label.
		"movl $0, %0\n\t"	//set result
		"jmp 4f\n\t"		

		"1:\n\t"		
		"movl $1, %0\n\t"	
		"jmp 4f\n\t"		

		"2:\n\t"		
		"movl $2, %0\n\t"	
		"jmp 4f\n\t"		

		"3:\n\t"		
		"movl $3, %0\n\t"	
		"jmp 4f\n\t"		

		"4:\n\t"		//finish

		:"=r"(result)		//output variables and registers
		:"x"(dummy), "x"(x)	//input variables and registers
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

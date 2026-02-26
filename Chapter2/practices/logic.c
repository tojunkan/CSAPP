#include <stdio.h>

int main()
{
	int a=0;
	printf("now variable a is :%d\n", a);
	printf("the expression a && 5 / a is:\t%d\n", a && 5 / a);
	//here demonstrates the short-circuit evaluation.
	//when a equals zero, the expression a && x (x can be anything) will become zero.
	//so the compiler will output 0 straightforward, neglecting the value of x.
	//that's why here 5/a doesn't raise error.
	if(a!=0)printf("the expression a & 5 / a is:\t%d", a & 5 / a);
	//however, the bitwise calculation cannot try short-circuit evaluation, that is a feature of logic calculation.
	else printf("cannot calculate the expression a & 5 / a : a is zero.\n");
	
	int *p = NULL;
	printf("pointer p points to the address %p, which means p is an empty pointer that doesn't point to any value.\n", p);
	printf("the expression p&&*p++ is:\t%d.\n", p&&*p++);
	//the *p++ doesn't raise any arror becouse the first argument of && is NULL(0)
	//so the compiler will output 0 directly.
	return 0;
}

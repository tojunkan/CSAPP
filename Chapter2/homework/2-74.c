#include <stdio.h>
//difficulty: **

int add_ok(int a, int b) {
	if(a > 0 && b > 0 && a+b < 0)return 0;
	else if(a < 0 && b < 0 && a+b >=0)return 0;
	return 1;
}

/* Determine whether arguments can be sbtracted without overflow.*/
int sub_ok(int a, int b) {
	if(b == 0x80000000) return a>-1 ? 0 : 1;
	else return add_ok(a, -b);
}

int main()
{
	int x, y;
	printf("please enter two integer x and y.\n");
	scanf("%d%d", &x, &y);
	if(add_ok(x, y))printf("the addition won't cause overflow.\n");
	else printf("the addition will cause overflow.\n");
	printf("\n");
	if(sub_ok(x, y))printf("the subtraction won't cause overflow.\n");
	else printf("the subtraction will cause overflow.\n");

	return 0;
}

#include <stdio.h>

void swap(int *x, int *y) {
	if(x == y)return;
	//here has to check if the pointer x and y points to the same memory.
	//if not then the below commands will become 0 ^ 0, which is unexpected.
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}

int main()
{
	int n, a[10];
	printf("please enter the length of the array.\n");
	scanf("%d", &n);
	printf("\nnext please enter all elements.\n");
	for(int i=0;i<n;i++)scanf("%d", &a[i]);
	printf("\nnow starts to swap the array.\n");
	for(int left=0, right=n-1;
			left<right;//left == right is not needed, because for the odd-length array, the midst element needn't to be swaped.
			left++, right--)
		swap(&a[left], &a[right]);
	for(int i=0;i<n;i++)printf("%d%c", a[i], i==n-1?'\n':' ');
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//difficulty:*
//

typedef unsigned char *byte_pointer;
void show_byte(byte_pointer a, size_t len) {
        for(size_t i=len;i>0;i--)
                printf(" %.2x", a[i-1]);
        printf("\n");
}

void show_bits(byte_pointer a, size_t len) {
        unsigned char tmp;
        for(size_t i=len;i>0;i--)
        {
                printf(" ");
                for(int j=7;j>=0;j--)
                        printf("%d", (a[i-1]>>j) & 1);
        }
        printf("\n");
}

/* library function calloc has the following declaration*/
void *calloc(size_t nmemb, size_t size);
/*According to the library documentation, 
 * "The function calloc allocates memory for an array of memb elements, 
 * each with bits size bytes. The memory is set to 0. 
 * If nmemb is 0, calloc returns NULL."
 * Write an implementation of calloc that calls malloc to perform allocation and memset to set memory to 0.
 *  Your code should be free of any vulnerabilities caused by arithmetic overflow, 
 *  and it should work regardless of the number of bits in a size_t datatype.
 *  For reference, the functions malloc and memset are declared as follows:
 * void *malloc(size_t size);
 * void *memset(void *s, int c, size_t n);
 * */

void *calloc(size_t nmemb, size_t size) {
	size_t tot = nmemb * size;
	if(nmemb == 0 || tot/nmemb != size)return NULL;//the multiplication might cause overflow. for detail, you can check Chapter2/practices/check_overflow.c
	printf("the multiplication does not cause overflow.\ntotal size is: %zu\n", tot);
	void *arr = malloc(tot);
	if(arr == NULL)return NULL;
	arr = memset(arr, 0, tot);
	return arr;
}

int main()
{
        size_t x, y;
        printf("Please enter two numbers. the program will allocate an array that has x elements, each with the size of y bytes.\n");
        scanf("%zu%zu", &x, &y);
        show_byte((byte_pointer)&x, sizeof(size_t));
        show_bits((byte_pointer)&x, sizeof(size_t));
        show_byte((byte_pointer)&y, sizeof(size_t));
        show_bits((byte_pointer)&y, sizeof(size_t));
        void *p = calloc(x, y);
	printf("the array is at:%p", p);
        return 0;

}

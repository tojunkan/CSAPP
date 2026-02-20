#include<stdio.h>
#include<string.h>
//difficulty:**
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

/* Copy integer into buffer if space is available */
void copy_int(int val, void *buf, int maxbytes) {
	//if (maxbytes-sizeof(val) >= 0) 
	/*this condition will always return true, 
	 * because the function sizeof will retrun an unsigned number, 
	 * which will implicitly turn maxbytes into another unsigned number,
	 * causing whatever the result becoming an unsigned number, which is always larger than 0.*/
	if (maxbytes >= sizeof(val))//this won't cause flaw.
		memcpy(buf, (void *) &val, sizeof(val));
}
int main()
{
        int x=2147483647;
        show_byte((byte_pointer)&x, sizeof(int));
        show_bits((byte_pointer)&x, sizeof(int));
        return 0;
}

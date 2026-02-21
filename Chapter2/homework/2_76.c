#include<stdio.h>
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
int main()
{
        int x, y;
        printf("Please enter two numbers. the program will give you the saturating added answer.\n");
        scanf("%d%d", &x, &y);
        show_byte((byte_pointer)&x, w);
        show_bits((byte_pointer)&x, w);
        show_byte((byte_pointer)&y, w);
        show_bits((byte_pointer)&y, w);
        int ans = saturating_add(x, y);
        printf("%d\n", ans);
        return 0;

}

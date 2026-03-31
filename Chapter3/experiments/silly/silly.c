int silly(int x, int y, int z)
{
	if( z<= 0)return z;
	while(z > 0)z = (z - (z>>1)) * 3;
	return z;
}
/*
 *    0:   f3 0f 1e fa             endbr64
 *    4:   89 d0                   mov    %edx,%eax
 *    6:   85 d2                   test   %edx,%edx
 *    8:   7f 0a                   jg     14 <silly+0x14>
 *            ^
 *           /_\
 *            |
 *            |
 *            here 0xa means it's a positive number(demical 10), 
 *            indicating that program should jump to 
 *            0xa(the index of the code following jump code) + 
 *            0xa(the number presented here) = 
 *            0x14(the object index).
 *    a:   c3                      ret
 *    b:   89 c2                   mov    %eax,%edx
 *    d:   d1 fa                   sar    $1,%edx
 *    f:   29 d0                   sub    %edx,%eax
 *   11:   8d 04 40                lea    (%rax,%rax,2),%eax
 *   14:   85 c0                   test   %eax,%eax
 *   16:   7f f3                   jg     b <silly+0xb>
 *            ^
 *           /_\
 *            |
 *            |
 *            here 0xf3 means it's a negative number(-0xd), indicating
 *            that program should jump to 
 *            0x18(the index of the code following jump code) - 
 *            0xd(the number presented here) = 
 *            0xb(the object index).
 *   18:   c3                      ret
 * this example shows that instructions using PC-relative encouding of the jump targets.
 * This encoding way is not only compact but also allows the program to be shift to any positions in memory without alteration.
 */

#include <stdio.h>

/* Implementation of library function gets() */
char *gets(char *s) {
	int c;
	char *dest = s;
	while ((c = getchar()) != '\n' && c != EOF)
		*dest++ = c;
	if(c == EOF && dest == s)
		/* No characters read */
		return NULL;
	*dest++ = '\0'; /* Terminate string */
	return s;
}

/*read input line and write it back */
void echo() {
	char buf[8]; /* Wey too small! */
	gets(buf);
	puts(buf);
}

/* use perameter -fno-stack-protector to compile, 
 * and you'll find that gcc will allocate 16 bytes for echo().*/

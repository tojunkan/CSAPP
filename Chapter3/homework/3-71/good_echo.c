#include<stdio.h>
#include<string.h>
#define BATCH_SIZE 8
//difficulty:*

void good_echo() {
	char buffer[BATCH_SIZE];
	while(fgets(buffer, BATCH_SIZE, stdin) != NULL) {
		fputs(buffer, stdout);
		if(strchr(buffer, '\n'))
			break;
	}
}

int main(int argc, char* argv[]) {
	good_echo();
	return 0;
}

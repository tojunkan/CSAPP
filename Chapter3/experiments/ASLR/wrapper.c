#include <stdio.h>
#include <stdlib.h>

int main() {

	freopen("addresses.txt", "w", stdout);

	for(int i=0;i<10000;i++)
		system("./ASLR_test");

	fclose(stdout);
	return 0;
}

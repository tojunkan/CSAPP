long mult2(long, long);

void multstore(long x, long y, long *dest) {
	long t = mult2(x, y);
	*dest = t;
}
//try run:
//gcc -Og -S mstore.c to get the assembly-code file.
//gcc -Og -c mstore.c to get the object-code file.

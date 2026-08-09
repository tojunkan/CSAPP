long fun_a(unsigned long x) {
	long val = 0;
	while(x != 0) {
		val ^= x;
		x >>= 1;
	}
	return val & 1;
}
// this function is designed to check the parity of number of ones in the binary expression of the x.

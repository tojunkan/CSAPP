long fun_b(unsigned long x) {
	long val = 0;
	long i;
	for (i = 64;i != 0; --i) {
		val += val;
		val |= (x&1);
		x >>=1;
	}
	return val;
}
// it is recommended to assemble this program with -O1, rather than -Og.
// this function gives out the bit-reversal of a value. Note that this is NOT endianness reversal.

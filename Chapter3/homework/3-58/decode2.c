long decode2(long x, long y, long z){
	y = y-z;
	x = x*y;
	long t=y;
	t<<=63;
	t>>=63;
	t ^= x;
	return t;
}

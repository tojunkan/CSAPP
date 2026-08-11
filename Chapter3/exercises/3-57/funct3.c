double funct3(int *ap, double b, long c, float *dp) {
	float f = *dp;
	if(b > *ap)
		return c * f;
	return c + 2 * f;
}

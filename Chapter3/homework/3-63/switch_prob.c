//difficulty:**
long switch_prob(long x, long n) {
	long result = x;
	switch(n) {
		case 62:
		case 60:
			result = 8*x;
			break;
		case 63:
			result = x>>3;
			break;
		case 64:
			x = 15*x;
		case 65:
			x *= x;
		defalut:
			result = 75 + x;
			break;
	}
	return result;
}

int main() {
	return 0;
}

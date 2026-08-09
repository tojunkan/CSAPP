long fact_while(long n) {
	long result = 1;
	while(n > 1) {
		result *= n;
		n = n - 1;
	}
	return result;
}
// this program realizes factor by while loop.
// in gcc, while loop can be assembled in two ways:
// first one is "jump to middle", you can check it with optimizing factor "-Og";
// the other one is "guarded-do", you can check it with optimizing factor "-O1".
//
// you can check with the assembled goto version of the program, they should be exactly the same.

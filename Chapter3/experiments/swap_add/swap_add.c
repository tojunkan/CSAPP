long swap_add(long *xp, long *yp) {
	long x = *xp;
	long y = *yp;
	*xp = y;
	*yp = x;
	return x + y;
}

long caller() {
	long arg1 = 534;
	long arg2 = 1057;
	long sum =swap_add(&arg1, &arg2);
	long diff = arg1 - arg2;
	return sum * diff;
}

// compile this file and you will find that, 
// when caller() is called, the stack will allocate 40 bytes, rather than 24.
// this is because of two reason.
// 
// First, ABI (Application Binary Interface) regulates that:
// when a call instruction is about to be executed, the register %rsp must be multiple of 16, not just 8. When caller() is called by main(), the next instruction in function main will also be pushed into the stack, which makes the %rsp points to a value that mods 16 is 8. caller also needs to call swap_add(), so the program will get 8 bytes first. 
//
// Second, to protect stack frame from attackers, kernels will allocate another 8 bytes for a value known as "canary". this value is not initiallized, thus remains randomly. when the function is finished, the kernel will check if this value is changed. if so, then that means attack has occured, and program will be killed. So there's another 8 bytes.
//
// and you'll find that that two args and canary value are 24 bytes, so we need another 8 bytes to align with 16.

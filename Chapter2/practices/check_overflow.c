#include <stdio.h>
#include <stdint.h>

int add_ok(int a, int b) {
	if(a > 0 && b > 0 && a+b < 0)return 0;
	else if(a < 0 && b < 0 && a+b >=0)return 0;
	return 1;
}

int sub_ok(int a, int b) {
	if(b == 0x80000000) return a>-1 ? 0 : 1;
	else return add_ok(a, -b);
}

int mul_ok(int a, int b) {
	//long long ans = ((long long)a * (long long)b);
	long long ans = (long long)a*b;//here means cast a to long long and then perform multiplication.(also b will cast to long long.)
	//here is critical. if we instead wrote the line as 
	//long long ans = a*b;
	//then the product would be computed as a 32-bit value and then sign extended to 64bits.
	return ans == (int) ans;
	//see if casting to int preserves value.
	//this method is easy to understand. if the multiplication dosen't overflow, then the upper 32 digits should be totally 1 or totally 0.

	//int p = a * b;
	//return a == 0 || p/a == b;
	//the proof is quite long. Obviously, it's not realistic to test this function for all possible x and y. Even if you could run 10 billion tests per second, it would require 58 years to test all combinations when data type int is 32 bits.(although it's possible for data type short.)
	//So we need a more principled approach, following the proposed set of arguments:
	//ONE. We know that x*y can be written as a 2w-bit two's-complement number. Let u denote the unsigned number reprezented by the lower w bits, and v denote the upper w bits. 
	//Then we can see that x * y = z = v * 2^w + u, where p(the actuall product in the two's complement) equals U2T(u). Unfolding the function U2T(u) we know that p=u(when u <= 2^(w-1) - 1) or p=q - 2^w(when u >= 2^(w-1)), so we have (z-p) mod 2^w = 0, which means we have an integer t satisfy equation z = p + t*2^w.
	//When t=0, we'll have z=p. Since p falls in the interval of int, so x * y = z also falls in the interval of int. In that case, the multiplication does not overflow.
	//When t >=1, we'll have z >= p + 2^w >= -2^(w-1) + 2^w=2^(w-1). TMax = 2^(w-1) - 1, so we found that z>=TMax, and the multiplication does overflow in that case.
	//Same thing happens when t <=-1. We'll have z <= p - 2^w <= 2^(w-1) - 1 - 2^w = -2^(w-1) - 1. TMin = -2^(w-1), so we found that z<=TMin, and the multiplication overflow in that case.
	//TWO. By definition of integer division, dividing p by nonzero x gives a quotient q and a remainder r such that p = x * q + r, and |r|<|x|.(here use absolute values because the sign of r and x may differ. The remainder in mathematic degree should be non-negative, but in computer science degree, the remainder has the same sign with the dividend. For instance, when p=-7, x=2, then q=-3, r=-1 instead of q=-4, r=1.
	//THREE. Suppose q=y. Then we have x*y = z = p + t*2^w = q*x+r +t*2^w. From this we can see that r + t * 2^w = 0. From the argument 2 we found that absolute value of r<=2^(w-1), while the absolute value of t*2^w is bigger or equal than 2^w. So this identitiy can hold only if t = r = 0.
	//Suppose r=t=0, Then we'll have x*y = x*q, implying q=y.
	//
	//The above proof analyzed the situation when x != 0. When x=0, multiplication of course not overflow.
}

int main()
{
	int x, y;
	printf("please enter two integer x and y.\n");
	scanf("%d%d", &x, &y);
	if(add_ok(x, y))printf("the addition won't cause overflow.\n");
	else printf("the addition will cause overflow.\n");
	if(sub_ok(x, y))printf("the subtraction won't cause overflow.\n");
	else printf("the subtraction will cause overflow.\n");


	if(mul_ok(x, y))printf("the multiplication won't cause overflow.\n");
	else printf("the multiplication will cause overflow.\n");

	return 0;
}

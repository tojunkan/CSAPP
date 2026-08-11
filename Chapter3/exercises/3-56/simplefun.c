#include<math.h>

#define EXPR1(x) \
	fabs(x)


double simplefun1(double x) {
	return EXPR1(x);
}
#define EXPR2(x) \
	0


double simplefun2(double x) {
	return EXPR2(x);
}
#define EXPR3(x) \
	-x


double simplefun3(double x) {
	return EXPR3(x);
}


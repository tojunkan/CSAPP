#include<stdio.h>
#include<math.h>
//when compiling, the math library has to be connected.
//which means it's necessary to write code like this:
//	gcc float_cal_demo.c -lm -o float_cal_demo
//this is a program to show some special float values, and how do they calculate.
//
#define POS_INFINITY 1e400 //the lagerst finite number that can be represented with double precision is around 1.8e308.
#define NEG_INFINITY (-POS_INFINITY) //positive infinity and negative infinity are each other's additive inverse. add quotes to make sure the priority (because what marcos do basically is just text replacement).
#define NEG_ZERO 1/NEG_INFINITY //-0 is equal to 1 divided by negative infinity, which is conform the intuition.


//actually, these marcos has been written in the file float.h.
#include<float.h> //include the file here will overwrite the marcos above.
typedef unsigned char *byte_pointer;

void show_byte(byte_pointer a, size_t len) {
        for(size_t i=len;i>0;i--)
                printf(" %.2x", a[i]);
        printf("\n");
}

void show_double(double *num) {
        show_byte((byte_pointer) num, sizeof(double));
}

int isnan(double num) {
	unsigned long long a = *(unsigned long long *)&num;
	return (a & 0x7ff0000000000000 == 0x7ff0000000000000) &&
	       (a & 0x000fffffffffffff != 0);
}
//note: a feature for NaN is that, NaN != NaN returns true, and
//any other comparisons will return false.
//for example, 	NaN == Inf -> false
//		Nan >= 1   -> false
//however, the follow writing:
//	return num != num;
//is not recommended, 
//because C standards have not defined the operator "!=" for NaN values.
//that may trigger errors like FE_INVALID.

int isinf(double num) {
	unsigned long long a = *(unsigned long long *)&num;
	//more safe version: 
	//	unsigned long long a;
	//	memcpy(*a, *num, sizeof(double));
	//	note that memcpy needs library string.h .
	return (a & 0x7ff0000000000000 == 0x7ff0000000000000) &&
	       (a & 0x000fffffffffffff == 0);
	//here uses 0x000fffffffffffff instead of 0x800fffffffffffff because it's no need to check if it's positive ones or negative ones.
	//here needs check bits one by one instead of writing:
	//	return num == INFINITY || num == -INFINITY;
	//is because that the operator "==" for INFINITY is not required in C standards.
	//in other words, it might trigger errors(FE_INVALID) in some machine.
	//and also, the function is the replacement for "==".
}
void print_double(double num) {
	printf("bitmode:\n");
	show_double(&num);
	printf("value:\n");

	if (isnan(num)){printf("NaN\n");}
	else if (isinf(num))
	{
		if (num>0)printf("+inf\n");
		else printf("-inf\n");
	}
	else printf("%.6g\n", num);
}

void test_unary(const char* func_name, double(*func)(double)) {
	//here used a function pointer.
	printf("============test: %s(x)============\n", func_name);

	double test_cases[] = { 4.0, 0.0, -0.0, -1.0, DBL_MAX, -DBL_MAX, 
				INFINITY, -INFINITY, NAN, 2.5, -2.5, 1.0,
				-1.0, 0.0, M_PI, -M_PI/2, 100.0, -100.0};

    	const char* case_names[] = {	"4.0", "0.0", "-0.0", "-1.0", 
					"DBL_MAX","-DBL_MAX", "inf", 
					"-inf", "NaN", "2.5", "-2.5", 
					"1.0", "-1.0", "0.0", "pi", 
					"-pi/2", "100.0", "-100.0"};

	double res;
	for(int i=0; i < sizeof(test_cases)/sizeof(double); i++)
	{
		printf("\n%s(%s) = \n", func_name, case_names[i]);
		res = func(test_cases[i]);
		print_double(res);
	}
}

void test_binary(const char* func_name, double (*func)(double, double)) {
	
	printf("============test: %s(x)============\n", func_name);

	typedef struct {
		double x;
		double y;
		const char* x_str;
		const char* y_str;
    	} TestCase;
	//c grammer is a bit different from c++ here.
	
	TestCase test_cases[] = {
		{5.0, 2.0, "5.0", "2.0"},
		{4.0, 0.5, "4.0", "0.5"},
		{0.0, 2.0, "0.0", "2.0"},
		{0.0, -1.0, "0.0", "-1.0"},
		{INFINITY, 2.0, "inf", "2.0"},
		{2.0, INFINITY, "2.0", "inf"},
		{1.0, INFINITY, "1.0", "inf"},
		{INFINITY, 0.0, "inf", "0.0"},
		{NAN, 0.0, "NaN", "0.0"},
		{0.0, NAN, "0.0", "NaN"},
		{-1.0, 0.5, "-1.0", "0.5"},
		{5.0, 0.0, "5.0", "0.0"},
		{INFINITY, 2.0, "inf", "2.0"},
		{5.0, INFINITY, "5.0", "inf"},
		{INFINITY, INFINITY, "inf", "inf"},
		{NAN, 2.0, "NaN", "2.0"},
		{5.0, NAN, "5.0", "NaN"},
		{INFINITY, -INFINITY, "inf", "-inf"},
		{-INFINITY, INFINITY, "-inf", "inf"},
		{NAN, NAN, "NaN", "NaN"},
		{3.0, 7.0, "3.0", "7.0"},
		{-3.0, 7.0, "-3.0", "7.0"},
		{3.0, -7.0, "3.0", "-7.0"},
		{-3.0, -7.0, "-3.0", "-7.0"}
	};

	double res;
	for(int i=0; i < sizeof(test_cases)/sizeof(TestCase); i++)
	{
		printf("\n%s(%s, %s) = \n", func_name, test_cases[i].x_str, test_cases[i].y_str);
		res = func(test_cases[i].x, test_cases[i].y);
		print_double(res);
	}
}

double emptyfunc(double x){return x;}
int main()
{
	int buff;
	printf("a display of test_cases\n");
	test_unary("test_case", emptyfunc);
	printf("test program for special double values.\n");
	printf("supported functions are:\n \
		exp is represented by 1;\n \
		log is represented by 2;\n \
		sin is represented by 3;\n \
		asin is represented by 4;\n \
		sinh is represented by 5;\n \
		cosh is represented by 6;\n \
		sqrt is represented by 7;\n \
		ceil is represented by 8;\n \
		floor is represented by 9.\n");
	printf("type the according function name to check the result.\n");
	scanf("%d", &buff);
	switch (buff) {
		case 1:test_unary("exp", exp);break;
		case 2:test_unary("log", log);break;
		case 3:test_unary("sin", sin);break;
		case 4:test_unary("asin", asin);break;
		case 5:test_unary("sinh", sinh);break;
		case 6:test_unary("cosh", cosh);break;
		case 7:test_unary("sqrt", sqrt);break;
		case 8:test_unary("ceil", ceil);break;
		case 9:test_unary("floor", floor);break;
		default:printf("not supported yet.\n");
	}
	printf("test program for special double values.\n");
	printf("supported functions are:\n \
		pow is represented by 1;\n \
		fmod is represented by 2;\n \
		fmax is represented by 3;\n \
		fmin is represented by 4;\n \
		copysign is represented by 5.\n");
	printf("type the according function name to check the result.\n");
	scanf("%d", &buff);
	switch (buff) {
		case 1:test_binary("pow", pow);break;
		case 2:test_binary("fmod", fmod);break;
		case 3:test_binary("fmax", fmax);break;
		case 4:test_binary("fmin", fmin);break;
		case 5:test_binary("copysign", copysign);break;
		default:printf("not supported yet.\n");
	}
	return 0;
}

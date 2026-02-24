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

void test_conversion() {
	printf("============test: Type Conversions ============\n");
	
	//test cases for type conversion
	double double_values[] = {3.14, -3.14, 2.718, -2.718, 0.0, -0.0, 
				 INFINITY, -INFINITY, NAN, 1.5, -1.5, 2.5, -2.5};
	const char* double_names[] = {"3.14", "-3.14", "2.718", "-2.718", "0.0", "-0.0",
				      "inf", "-inf", "NaN", "1.5", "-1.5", "2.5", "-2.5"};
	
	printf("\n1. double to int (implicit and explicit):\n");
	for(int i=0; i<sizeof(double_values)/sizeof(double); i++) {
		double d = double_values[i];
		int i_implicit = d; //implicit conversion
		int i_explicit = (int)d; //explicit conversion
		printf("%s -> implicit int: %d, explicit (int): %d\n", 
		       double_names[i], i_implicit, i_explicit);
	}
	
	printf("\n2. double to float (implicit and explicit):\n");
	for(int i=0; i<sizeof(double_values)/sizeof(double); i++) {
		double d = double_values[i];
		float f_implicit = d; //implicit conversion
		float f_explicit = (float)d; //explicit conversion
		printf("%s -> implicit float: %.6g, explicit (float): %.6g\n",
		       double_names[i], f_implicit, f_explicit);
	}
	
	printf("\n3. int to double/float (implicit):\n");
	int int_values[] = {0, 1, -1, 123456, -123456, 2147483647, -2147483648};
	const char* int_names[] = {"0", "1", "-1", "123456", "-123456", "INT_MAX", "INT_MIN"};
	
	for(int i=0; i<sizeof(int_values)/sizeof(int); i++) {
		int n = int_values[i];
		double d = n; //implicit int to double
		float f = n;  //implicit int to float
		printf("%s -> double: %.6g, float: %.6g\n", int_names[i], d, f);
	}
	
	printf("\n4. mixed-type operations (int + double):\n");
	for(int i=0; i<5; i++) {
		int n = int_values[i];
		double d = double_values[i];
		double result = n + d; //int promoted to double
		printf("%s + %s = %.6g (int promoted to double)\n", 
		       int_names[i], double_names[i], result);
	}
}

//new function: test extended rounding functions
void test_rounding_extended() {
	printf("============test: Extended Rounding Functions ============\n");
	
	double test_cases[] = {3.14, -3.14, 2.5, -2.5, 1.5, -1.5, 3.7, -3.7,
			       0.0, -0.0, INFINITY, -INFINITY, NAN,
			       2.718, -2.718, 100.3, -100.3};
	const char* case_names[] = {"3.14", "-3.14", "2.5", "-2.5", "1.5", "-1.5", 
				    "3.7", "-3.7", "0.0", "-0.0", "inf", "-inf", "NaN",
				    "2.718", "-2.718", "100.3", "-100.3"};
	
	printf("\n1. round() - round to nearest integer, halfway cases away from zero:\n");
	for(int i=0; i<sizeof(test_cases)/sizeof(double); i++) {
		double result = round(test_cases[i]);
		printf("round(%s) = ", case_names[i]);
		if(isnan(result)) printf("NaN\n");
		else if(isinf(result)) printf("%s\n", result>0?"+inf":"-inf");
		else printf("%.6g\n", result);
	}
	
	printf("\n2. trunc() - truncate toward zero (remove fractional part):\n");
	for(int i=0; i<sizeof(test_cases)/sizeof(double); i++) {
		double result = trunc(test_cases[i]);
		printf("trunc(%s) = ", case_names[i]);
		if(isnan(result)) printf("NaN\n");
		else if(isinf(result)) printf("%s\n", result>0?"+inf":"-inf");
		else printf("%.6g\n", result);
	}
	
	printf("\n3. nearbyint() - round to nearest integer using current rounding mode:\n");
	for(int i=0; i<sizeof(test_cases)/sizeof(double); i++) {
		double result = nearbyint(test_cases[i]);
		printf("nearbyint(%s) = ", case_names[i]);
		if(isnan(result)) printf("NaN\n");
		else if(isinf(result)) printf("%s\n", result>0?"+inf":"-inf");
		else printf("%.6g\n", result);
	}
	
	printf("\n4. rint() - round to nearest integer, may raise inexact exception:\n");
	for(int i=0; i<sizeof(test_cases)/sizeof(double); i++) {
		double result = rint(test_cases[i]);
		printf("rint(%s) = ", case_names[i]);
		if(isnan(result)) printf("NaN\n");
		else if(isinf(result)) printf("%s\n", result>0?"+inf":"-inf");
		else printf("%.6g\n", result);
	}
	
	printf("\n5. Comparison of different rounding methods for key values:\n");
	double special_cases[] = {2.5, -2.5, 1.5, -1.5, 3.5, -3.5};
	const char* special_names[] = {"2.5", "-2.5", "1.5", "-1.5", "3.5", "-3.5"};
	
	for(int i=0; i<sizeof(special_cases)/sizeof(double); i++) {
		double x = special_cases[i];
		printf("\n%s:\n", special_names[i]);
		printf("  round()  = %.0f\n", round(x));
		printf("  trunc()  = %.0f\n", trunc(x));
		printf("  ceil()   = %.0f\n", ceil(x));
		printf("  floor()  = %.0f\n", floor(x));
		printf("  nearbyint() = %.0f\n", nearbyint(x));
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

	test_conversion();
	test_rounding_extended();
	return 0;
}

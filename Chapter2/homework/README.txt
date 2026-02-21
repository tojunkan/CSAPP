this file is a catalog for the following programs.
2_55: see ordering (big endianness or small endianness)
2_56: same as 2_55
2_57: extend show_bytes in 2_55 for type short, long, double, etc.
2_58: determine the endianness. return 1 when compiled and run on a little-endian machine, and return 0 otherwise.
2_59: yield a word consisting of the least significant byte of x, and the remaining bytes of y.
2_60: return an unsigned value in which byte i of argument x has been replaced by byte b.
2_61: 

Bit-level integer coding rules
In several of the following problems, we will artificially restrict what programming constructs you can use to help you gain a better understanding of the bit-level, logic, and arithmetic operations of C. In answering these problems, your code must follow these rules:
Assumptions
	Integers are represented in two’s-complement form.
	Right shifts of signed data are performed arithmetically.
	Data type "int" is "w" bits long. For some of the problems, you will be given a specific value for "w", but otherwise your code should work as long as "w" is a multiple of 8. You can use the expression sizeof(int)<<3 to compute "w".
Forbidden
	Conditionals(if or ?:),loops, switchstatements, function calls, and macro invocations.
	Division, modulus, and multiplication.
	Relative comparison operators (<, >, <=, and >=).
	Casting, either explicit or implicit.
Allowed operations
	All bit-level and logic operations.
	Left and right shifts, but only with shift amounts between 0 and w − 1.
	Addition and subtraction.
	Equality(==) and inequality(!=) tests.(Some of the problems do not allow these.)
	Integer constants INT_MIN and INT_MAX.
Even with these rules, you should try to make your code readable by choosing descriptive variable names and using comments to describe the logic behind your solutions.

this file is a catalog for the following programs.
2_55: see ordering (big endianness or small endianness)
2_56: same as 2_55
2_57: extend show_bytes in 2_55 for type short, long, double, etc.
2_58: determine the endianness. return 1 when compiled and run on a little-endian machine, and return 0 otherwise.
2_59: yield a word consisting of the least significant byte of x, and the remaining bytes of y.
2_60: return an unsigned value in which byte i of argument x has been replaced by byte b.
2_61: give out 1 when any bit of x equals 1 or 0, or any bit in the least significant byte of x equals 1 or 0. 0 otherwise.
2_62: yeild 1 when run on a machine that uses arithmetic right shifts for int's, and 0 otherwise.
2_63: transform an arithmetic right shift to logical right shift, and transform the logical right shift into arithmetic one.
2_64: return 1 when any odd bit of x equals 1; 0 otherwise.(assume w = 32).
2_65: return 1 when x contains an odd number of 1s; 0 otherwise.(assume w = 32).
2_66: generate mask indicating leftmost 1 in x.(assume w = 32).
2_67: yields 1 when run on a machine for which an int is 32 bits; 0 otherwise.
2_68: mask with least significant n bits set to 1.
2_69: do rotating left shift.(assume 0 <= n < w).
2_70: return 1 when x can be represented as an n-bit, 2's complement number; 0 otherwise.
2_71: extract a number with the length of a byte from an unsigned type.
2_72: copy an integer "val" into a buffer "buff", but it should do so only if enought space is avaliable in the buffer.
2_73: addittion that saturates to TMin or TMax.
2_74: return 1 if the computation x-y does not overflow. 0 otherwise.
2_75: compute the high-order w bits of x*y for unsigned and signed variables.
2_76: none(hand writing homework about calculating multiplications). HOWEVER, IN CHINESE VERSION, THIS PROGRAM IS TO REALIZE FUNCTION calloc.
2_77: divide x by power of two.(assume 0 <= k < w-1).
2_78: computes 3*x/4 for integer argument x, and replicate the fact that the computation 3*x may cause overflow.
2_79: computes 3*x/4 for integer argument x, which should not overflow and rounds toward zero.
2_80: generate the bit patterens that follow: 1...10...0(least k-th significant bits is 0) or 0...01...10...0(least j-th significant bits is 0, and then k length of 1s, and then turn to 0).
2_81: none(hand writing homework about bitwise calculation).
2_82: nont(hand writing homework about infinite expression of float numbers).
2_83: realise less than or equal function for two float type numbers.
2_84: none(hand writing homework about floating point format)
2_85: none(hand writing homework about special float values)
2_86: none(hand writing homework about float representation tests)
2_87: none(hand writing homework about rounding)
2_88: none(hand writing homework about casting between int, float and double)
2_89: compute a floating-point representation of 2^x.
2_90: none(hand writing homework about approximating pi value)


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

Bit-level floating-point coding rules
In the following problems, you will write code to implement floating-point functions, operating directly on bit-level representations of floating-point numbers. Your code should exactly replicate the conventions for IEEE floating-point operations, including using round-to-even mode when rounding is required.
Toward this end, we define data type float_bits to be equivalent to un
signed:
/* Access bit-level representation floating-point number */
typedef unsigned float_bits;
Rather than using data type float in your code, you will use float_bits.
You may use both int and unsigned data types, including unsigned and integer constants and operations. You may not use any unions, structs, or arrays. Most significantly, you may not use any floating-point data types, operations, or constants. Instead, your code should perform the bit manipulations that implement the specified floating-point operations.
The following function illustrates the use of these coding rules. For argument f, it returns ±0iff is denormalized (preserving the sign of f) and returns f otherwise.

void switch_eg_impl(long x, long n, long *dest) {
	/* Table of code pointers.
	 * this code makes use of support provided by GCC for jump tables, as an extention to the C language.
	 * The array "jt" contains seven endries, each of which is the address of a block of code.
	 * These locations are defined by labels in the code, and indicated in the entries in "jt" by code pointers, 
	 * consisting of the labels prefixed by "&&".
	 * We already know that the operator "&" creates a pointer for a data value.
	 * In making this extention, the authors of GCC created a new operator && to create a pointer for a code location.*/
	static void *jt[7] = {
		&&loc_A, &&loc_def, &&loc_B,
		&&loc_C, &&loc_D, &&loc_def,
		&&loc_D
	};
	unsigned long index = n - 100;
	long val;
	
	if(index > 6)
		goto loc_def;

	/* Multiway branch */
	goto *jt[index];

loc_A:		/* Case 100 */
	val = x * 13;
	goto done;
loc_B:		/* Case 102 */
	x = x + 10;
	/* Fall through */
loc_C:		/* Case 103 */
	val = x + 11;
	goto done;
loc_D:		/* Case 104, 106 */
	val = x * x;
	goto done;
loc_def:	/* Default case */
	val = 0;
done:
	*dest = val;
}

/* Example of for loop containing a continue statement *
 * Sum even numbers between 0 and 9 */

long sum() {

	long res = 0;
	long i;
	for(i = 0; i < 10; i++ ) {
		if(i & 1)
			continue;
		res += i;
	}
	return res;
}

// first of all, it is not valid to write a loop outside of a function body (aka global scope)
//
// long sum() {
// 	long res = 0;
// 	long i;
// 	i=0;
// 	goto test;
// loop:
// 	if(i & 1)
// 		goto loop;
// 	res += i;
// 	i++;
// test:
// 	if(i < 10)
// 		goto loop;
// 	return res;
// }
// if you think that the continue instruction in for loop will be handled just like in the while loop (just as the above code has shown),
// then you are making a big mistake. the update-expr is also skipped, which is unexpected.
// 
// the true goto-version may look like (guarded-do version):
// long sum() {
// 	long res = 0;
// 	long i;
// 	i = -1;
// 	if(i >= 10)
// 		goto done;
// loop:
// 	i++;
// 	if(i & 1) {
// 		goto loop;
// 	}
//	res += i;
// test:
// 	if(i < 10)
// 		goto loop;
// done:
// 	return res;
// }
//

long lt_cnt = 0;
long ge_cnt = 0;

int absdiff(int x, int y)
{
	if(x < y)
	{
		lt_cnt++;
		return y - x;
		//in fact, the subtraction here might cause overflow,
		//giving out an unexpected negative number.
		//but since we're not concerning if the code is robust,
		//we'll just leave that question there.
	}
	else
	{
		ge_cnt++;
	       	return x - y;
	}
}

int gotodiff(int x, int y)
{
	int result;
	if(x >= y) goto x_ge_y;
	lt_cnt++;
	result = y - x;
	return result;
x_ge_y:
	ge_cnt++;
	result = x - y;
	return result;
}

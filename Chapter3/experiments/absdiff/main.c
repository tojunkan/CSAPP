extern int lt_cnt;
extern int ge_cnt;

int absdiff(int x, int y);
int gotodiff(int x, int y);

int main()
{
	int x, y;
	x = 10, y = 0;
	absdiff(x, y);
       	gotodiff(x, y);
	x = 0, y = 0;
	absdiff(x, y);
       	gotodiff(x, y);
	return 0;
}

#include <iostream>
using namespace std;

void swap1(int a, int b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

void swap2(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}

void swap3(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int a[5] = {1,2,3,4,5};
	int *p = (int *)(&a + 1);
	cout << *(a + 1) << endl << *(p - 1) << endl;
}
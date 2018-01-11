#include<iostream>
using namespace std;

int list(int A[], int n)
{
	int *d = new int[n];
	int len = 1;
	for (int i = 0; i < n; i ++) {
		d[i] = 1;
		for (int j = 0; j < i; j ++) {
			if (A[j] <= A[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
		if (d[i] > len) {
			len = d[i];
		}
	}
	delete[] d;
	return len;
}

int main()
{
	int a[] = {5,3,4,8,6,7};
	int b[] = {5,4,1,3,5,9,8,12};
	cout << list(a, 6) << endl;
	cout << list(b, 8) << endl;
	return 0;
}
#include<iostream>
using namespace std;

int maxList(int *a, int n)
{
	int max = 0;
	for (int i = 0; i < n; i ++) {
		if (a[i] <= 0) {
			continue;
		}
		int sum = 0;
		for (int j = i; j < n; j ++) {
			sum += a[j];
			if (sum > max) {
				max = sum;
			}
		}
	}
	return max;
}

int main()
{
	int a[6] = {-2, 11, -4, 13, -5, -2};
	cout << maxList(a, 6) << endl;
	return 0;
}
#include<stdio.h>

int test1(int *a, int n)
{
	int sum = 0;
	for (int i = 1; i < n + 1; i ++) {
		sum += i;
	}
	for (int j = 0; j < n - 1; j ++) {
		sum -= a[j];
	}
	return sum;
}

int test2(int *a, int n)
{
	int flag = 1, temp;
	for (int i = 1; i < n - 1 && flag == 1; i ++) {
		flag = 0;
		for (int j = 0; j < n - i - 1; j ++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
	for (int i = 0; i < n - 1; i ++) {
		if (a[i] + 1 != a[i + 1]) {
			return a[i] + 1;
		}
	}
}

int main()
{
	int a[9] = {9,10,5,4,1,3,6,2,8};
	printf("%d\n", test1(a, 10));
	printf("%d\n", test2(a, 10));
}
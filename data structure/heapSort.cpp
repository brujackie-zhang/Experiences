#include<stdio.h>

void adjust(int a[], int i, int n)
{
	int j, tmp;
	tmp = a[i];
	j = 2 * i;
	while (j <= n) {
		if (j < n && a[j] > a[j + 1]) {
			j ++;
		}
		if (tmp <= a[j]) {
			break;
		}
		a[j / 2] = a[j];
		j = j * 2;
	}
	a[j / 2] = tmp;
}

void heapSort(int a[], int n)
{
	int tmp;
	for (int i = n / 2; i > 0; i --) {
		adjust(a, i, n);
	}
	for (int i = n - 2; i >= 0; i --) {
		tmp = a[i + 1];
		a[i + 1] = a[0];
		a[0] = tmp;
		adjust(a, 0, i);
	}
}

int main()
{
	int a[10] = {12,45,789,698,36,54,78,95,41,25};
	heapSort(a, 10);
	for (int i = 0; i < 10; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
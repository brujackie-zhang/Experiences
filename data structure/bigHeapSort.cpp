#include<stdio.h>

void adjust(int a[], int i, int n)
{
	int temp, j;
	temp = a[i];
	j = 2 * i;
	while (j <= n) {
		if (j < n && a[j] < a[j + 1]) {
			j ++;
		}
		if (temp >= a[j]) {
			break;
		}
		a[j / 2] = a[j];
		j = 2 * j;
	}
	a[j / 2] = temp;
}

void heapSort(int a[], int n)
{
	int temp;
	for (int i = n / 2; i > 0; i --) {
		adjust(a, i, n);
	}
	for (int i = n - 2; i >= 0; i --) {
		temp = a[i + 1];
		a[i + 1] = a[0];
		a[0] = temp;
		adjust(a, 0, i);
	}
}

int main()
{
	int a[10] = {18,78,45,96,32,126,254,9874,14,520};
	heapSort(a, 10);
	for (int i = 0; i < 10; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
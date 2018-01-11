#include<stdio.h>
void selectSort(int a[], int n)
{
	int temp, min, i, j;
	for (i = 0; i < n - 1; i ++) {
		min = i;
		for (j = i + 1; j < n; j ++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		if (min != i) {
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
}

int main()
{
	int a[10] = {45,78,456,12,0,14,56,98,74,26};
	for (int i = 0; i < 10; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	selectSort(a, 10);
	for (int i = 0; i < 10; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
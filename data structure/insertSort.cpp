#include<stdio.h>
void insertSort(int a[], int n)
{
	int temp, j;
	for (int i = 1; i < n; i ++) {
		temp = a[i];
		j = i - 1;
		while (j >= 0 && temp > a[j]) {
			a[j + 1] = a[j --];
		}
		a[j + 1] = temp;
	}
}

int main()
{
	int a[10] = {2,5,9,78,41,598,789,41,25,36};
	for (int i = 0; i < 10; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	insertSort(a, 10);
	for (int i = 0; i < 10; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
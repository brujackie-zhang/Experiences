#include<stdio.h>

void bubbleSort(int a[], int n)
{
	int i, j, tmp, flag = 1;
	for (i = 1; i < n && flag == 1; i ++) {
		flag = 0;
		for (j = 0; j < n - i; j ++) {
			if (a[j] > a[j + 1]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}

int main()
{
	int a[10] = {12,52,45,6,0,32,1,45,78,456};
	for (int i = 0; i < 10; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	bubbleSort(a, 11);
	for (int i = 0; i < 10; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
#include<stdio.h>

int countSort(int a[], int n)
{
	int maxLen = n + 1;
	int b[maxLen];
	int index = 0;
	for (int i = 0; i < n; i ++) {
		if (!b[a[i]]) {
			b[a[i]] = 0;
		}
		b[a[i]] ++;
	}
	for (int j = 0; j < maxLen; j ++) {
		while (b[j] > 0) {
			a[index ++] = j;
			b[j] --;
		}
	}
	return *a;
}

int main()
{
	int a[10] = {15,7,45,96,1,52,6,3,0,78};
	countSort(a, 10);
	for (int i = 0; i < 10; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
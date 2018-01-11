#include<stdio.h>

void shellSortBubble(int a[], int n)
{
	int temp, i, j, flag, gap = n;
	while (gap > 1) {
		gap = gap / 2;
		do {
			flag = 0;
			for (i = 0; i < n - gap; i ++) {
				j = i + gap;
				if (a[i] > a[j]) {
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					flag = 1;
				}
			}
		} while (flag != 0);
	}
}

int main()
{
	int a[10] = {7,85,45,74,123,69,5,41,0,12};
	for (int i = 0; i < 10; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	shellSortBubble(a, 10);
	for (int i = 0; i < 10; i ++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
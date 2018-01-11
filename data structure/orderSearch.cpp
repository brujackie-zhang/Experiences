#include<stdio.h>

int orderSearch(int a[], int n, int key)
{
	for (int i = 0; i < n; i ++) {
		if (a[i] == key)
			return i;
	}
	return -1;
}

int midSearch(int a[], int n, int key)
{
	int low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == key) return mid;
		if (a[mid] >= key) high = mid - 1;
		if (a[mid] <= key) low = mid + 1;
	}
	return -1;
}

int main()
{
	int a[10] = {7,9,78,45,74,12,58,45,125,789};
	int b[10] = {7,9,12,45,45,45,74,78,125,789};
	printf("%d\n", orderSearch(a, 10, 45));
	printf("%d\n", midSearch(b, 10, 45));
}
#include<stdio.h>
#include<stdlib.h>

void sort(int w[], int t[], int n)
{
	int temp;
	// int *w_tmp = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i ++) {
		t[i] = i;
		// w_tmp[i] = w[i];
	}
	for (int i = 0; i < n - 1; i ++) {
		for (int j = 0; j < n - i - 1; j ++) {
			if (w[j] > w[j + 1]) {
				temp = w[j];
				w[j] = w[j + 1];
				w[j + 1] = temp;
				temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
		}
	}
}

void load(int x[], int w[], int c, int n)
{
	int *t = (int *)malloc(n * sizeof(int));
	sort(w, t, n);
	for (int i = 0; i < n; i ++) {
		x[i] = 0;
	}
	for (int j = 0; j < n && w[t[j]] <= c; j ++) {
		x[t[j]] = 1;
		c -= w[t[j]];
	}
}

int main()
{
	int x[5], w[5], c, i;
	printf("Please input maximun loading:\n");
	scanf("%d", &c);
	printf("Please input the weight of box:\n");
	for (i = 0; i < 5; i ++) {
		scanf("%d", &w[i]);
	}
	load(x, w, c, 5);
	for (i = 0; i < 5; i ++) {
		if (x[i] == 1) {
			printf("%d ", i);
		}
	}
	return 0;
}
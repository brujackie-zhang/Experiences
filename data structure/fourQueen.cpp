#include<stdio.h>

int count = 0;
int isCorrect(int i, int j, int (*q)[10])
{
	int x, y;
	for (x = i, y = 0; y < 10; y ++) {
		if (q[x][y] == 1 && y != j) {
			return 0;
		}
	}
	for (y = j, x = 0; x < 10; x ++) {
		if (q[x][y] == 1 && x != i) {
			return 0;
		}
	}
	for (x = i - 1, y = j - 1; x >= 0 && y >= 0; x --, y --) {
		if (q[x][y] == 1) {
			return 0;
		}
	}
	for (x = i + 1, y = j + 1; x < 10 && y < 10; x ++, y ++) {
		if (q[x][y] == 1) {
			return 0;
		}
	}
	for (x = i + 1, y = j - 1; x < 10 && y >= 0; x ++, y --) {
		if (q[x][y] == 1) {
			return 0;
		}
	}
	for (x = i - 1, y = j + 1; x >= 0 && y < 10; x --, y ++) {
		if (q[x][y] == 1) {
			return 0;
		}
	}
	return 1;
}

void Queen(int j, int (*q)[10])
{
	int i, k;
	if (j == 10) {
		for (i = 0; i < 10; i ++) {
			for (k = 0; k < 10; k ++) {
				printf("%d ", q[i][k]);
			}
			printf("\n");
		}
		printf("\n");
		count ++;
	}
	for (i = 0; i < 10; i ++) {
		if (isCorrect(i, j, q)) {
			q[i][j] = 1;
			Queen(j + 1, q);
			q[i][j] = 0;
		}
	}
}

int main()
{
	int q[10][10];
	for (int i = 0; i < 10; i ++) {
		for (int j = 0; j < 10; j ++) {
			q[i][j] = 0;
		}
	}
	Queen(0, q);
	printf("Four Queen answer is %d\n", count);
}
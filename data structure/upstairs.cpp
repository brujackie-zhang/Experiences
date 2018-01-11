#include<stdio.h>
#define MAX_STEPS 20

int result[MAX_STEPS] = {0};
int count = 0;

void upStairs(int footStep, int upCount, int steps)
{
	if (upCount + footStep == MAX_STEPS) {
		result[steps] = footStep;
		for (int i = 0; i <= steps; i ++) {
			printf("%d ", result[i]);
		}
		printf("\n");
		count ++;
	}
	if (upCount + footStep > MAX_STEPS) return;
	result[steps] = footStep;
	upCount += footStep;
	steps ++;

	for (int i = 1; i <= 2; i ++) {
		upStairs(i, upCount, steps);
	}
}

void upStairs_All()
{
	upStairs(1, 0, 0);
	upStairs(2, 0, 0);
}

int main()
{
	upStairs_All();
	printf("up stairs sum is %d !\n", count);
}
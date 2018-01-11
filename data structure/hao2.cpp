#include<stdio.h>

int findMax(int *a, int row, int col, int *r, int *c)
{
    int sum = 0;
    for (int i = 0; i < row -1; i ++) {
        int sum1 = 0;
        int *r1 = a + i * col;
        int *r2 = a + (i + 1) * col;
        for (int j = 0; j < col - 1; j ++) {
            sum1 = r1[j] + r2[j] + r1[j + 1] + r2[j + 1];
            if (sum1 > sum) {
                *r = (i + 1);
                *c = (j + 1);
                sum = sum1;
            }
        }
    }
    return sum;
}

int main()
{
     int a[15] = {1,2,0,3,4,2,3,4,5,1,1,1,5,3,0};
    int r, c;
    printf("%d\n", findMax(a, 3, 5, &r, &c));
    return 0;
}
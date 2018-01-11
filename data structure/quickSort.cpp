#include<stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int a[], int left, int right)
{
    int x, y;
    if (left < right) {
        x = left;
        y = right + 1;
        while (1) {
            do {
                x ++;
            } while(!(a[left] <= a[x] || x == right));
            do {
                y --;
            } while(!(a[left] >= a[y]) || y == left);
            if (x < y) {
                swap(&a[x], &a[y]);
            } else {
                break;
            }
        }
        swap(&a[left], &a[y]);
        quickSort(a, left, y - 1);
        quickSort(a, y + 1, right);
    }
}

int main()
{
    int a[10] = {12,456,789,47,5,0,12,36,59,48};
    quickSort(a, 0, 9);
    printf("The sort result is:\n");
    for (int j = 0; j < 10; j ++) {
        printf("%d ", a[j]);
    }
    printf("\n");
}
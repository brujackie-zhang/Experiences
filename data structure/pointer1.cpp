#include<stdio.h>
int main()
{
	int a[5] = {1,2,3,4,5};
	int *p = &a[0];
	int i;
	for (i = 0; i < 5; i ++) {
		printf("a[%d]=%d\n", i, a[i]);
	}
	for (i = 0; i < 5; i ++) {
		printf("*(a+%d)=%d\n", i, *(a+i));
	}
	for (i = 0; i < 5; i ++) {
		printf("p[%d]=%d\n", i, p[i]);
	}
	for (i = 0, p = a; p < 5 + a; i ++, p ++) {
		printf("*(p+%d)=%d\n", i, *(p));
	}
}
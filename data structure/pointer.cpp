#include<stdio.h>
int main()
{
	int q = 12;
	int *s = &q;
	printf("&q=%p,s=%p\n", &q, s);
	printf("q=%d,*s=%d\n", q, *s);
	printf("&*s=%p,*&s=%p\n", &*s, *&s);
	printf("&s=%p\n", &s);
}
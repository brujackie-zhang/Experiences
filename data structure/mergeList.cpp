#include<stdlib.h>
#include<stdio.h>

typedef int ElemType;

typedef struct {
	int *elem;
	int length;
	int listSize;
} sqList;

void initSqList(sqList *L, int size)
{
	L -> elem = (int *)malloc(size * sizeof(ElemType));
	if (! L -> elem) exit(0);
	L -> length = 0;
	L -> listSize = size;
}

void insertElement(sqList *L, int i, ElemType e)
{
	ElemType *base, *insertPtr, *p;
	if (i < 1 || i > L -> length + 1) exit(0);
	if (L -> length >= L -> listSize) {
		base = (int *)realloc(L -> elem, (L -> listSize + 10) * sizeof(ElemType));
		L -> elem = base;
		L -> listSize = L -> listSize + 100;
	}
	insertPtr = &(L -> elem[i - 1]);
	for (p = &(L -> elem[L -> length - 1]); p >= insertPtr; p --) {
		*(p + 1) = *p;
	}
	*insertPtr = e;
	L -> length ++;
}

void destorySqList(sqList *L)
{
	int *p = L -> elem;
	free(p);
	L -> elem = NULL;
	L -> length = 0;
	L -> listSize = 0;
}

sqList mergeList(sqList list1, sqList list2)
{
	int *p1, *p2, *p3, *p1_last, *p2_last;
	sqList list3;
	p1 = list1.elem;
	p2 = list2.elem;
	initSqList(&list3, list1.length + list2.length);
	p3 = list3.elem;
	p1_last = list1.length + list1.elem - 1;
	p2_last = list2.length + list2.elem - 1;
	while (p1 <= p1_last && p2 <= p2_last) {
		if (*p1 <= *p2) {
			*p3 = *p1;
			p3 ++;
			p1 ++;
		} else {
			*p3 = *p2;
			p3 ++;
			p2 ++;
		}
		list3.length ++;
	}
	if (p1 <= p1_last) {
		while (p1 <= p1_last) {
			*p3 = *p1;
			p3 ++;
			p1 ++;
			list3.length ++;
		}
	} else {
		while (p2 <= p2_last) {
			*p3 = *p2;
			p3 ++;
			p2 ++;
			list3.length ++;
		}
	}
	return list3;
}

int main()
{
	sqList list1, list2, list3;
	int n, i, e;
	printf("Please input the length of list1:\n");
	scanf("%d", &n);
	initSqList(&list1, n);
	printf("Please input list1 content:\n");
	for (i = 1; i <= n; i ++) {
		scanf("%d", &e);
		insertElement(&list1, i, e);
	}

	printf("Please input the length of list2:\n");
	scanf("%d", &n);
	initSqList(&list2, n);
	printf("Please input list2 content:\n");
	for (i = 1; i <= n; i ++) {
		scanf("%d", &e);
		insertElement(&list2, i, e);
	}

	list3 = mergeList(list1, list2);

	printf("The content of list3 is:\n");
	for (i = 0; i < list3.length; i ++) {
		printf("%d ", list3.elem[i]);
	}
	printf("\n");

	destorySqList(&list1);
	destorySqList(&list2);
	destorySqList(&list3);
}
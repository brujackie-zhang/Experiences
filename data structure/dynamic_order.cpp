#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef int EleType;

typedef struct {
	int * elem;
	int length;
	int listSize;
} sqlist;

void initSqlist(sqlist *L)
{
	L -> elem = (int *)malloc(MAXSIZE * sizeof(EleType));
	if (! L -> elem) printf("error\n");
	L -> length = 0;
	L ->listSize = MAXSIZE;
}

void insertElem(sqlist *L, int i, EleType item)
{
	EleType *base, *insertPtr, *p;
	if (i < 1 || i > L -> listSize) printf("error\n");
	if (L -> length >= L ->listSize) {
		base = (EleType *)realloc(L -> elem, (L -> listSize + 10) * sizeof(EleType));
		L -> elem = base;
		L -> listSize = L -> listSize + 100;
	}
	insertPtr = &(L -> elem[i - 1]);
	for (p = &(L -> elem[L -> length -1]); p >= insertPtr; p --) {
		*(p + 1) = *p;
	}
	*insertPtr = item;
	L -> length ++;
}

void delElem(sqlist *L, int i)
{
	EleType *delItem, *q;
	if (i < 1 || i > L -> length) printf("error\n");
	delItem = &(L -> elem[i - 1]);
	q = L -> elem + L -> length - 1;
	for (++ delItem; delItem <= q; ++delItem) {
		*(delItem - 1) = *delItem;
	}
	L -> length --;
}

int main()
{
	sqlist L;
	int i;
	initSqlist(&L);
	for (i = 0; i < 15; i ++) {
		insertElem(&L, i + 1, i + 1);
	}
	printf("insert number list is:\n");
	for (i = 0; i < L.length; i ++) {
		printf("%d ", L.elem[i]);
	}
	delElem(&L, 5);
	printf("delete list is :\n");
	for (i = 0; i < L.length; i ++) {
		printf("%d ", L.elem[i]);
	}
	return 0;
}
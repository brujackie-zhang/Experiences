#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 10;

typedef int EleType;
typedef struct {
	int *elem;
	int length;
	int listsize;
} sqlist;

void initSqlist(sqlist *L)
{
	L -> elem = (int *)malloc(sizeof(EleType));
	if ( ! L -> elem) {
		cout << "error" << endl;
	}
	L -> length = 0;
	L -> listsize = MAX;
}

void insertElem(sqlist *L, int i, EleType item)
{
	EleType *base, *insertPer, *p;
	if (i < 1 || i > L -> listsize) {
		cout << "溢出" << endl;
	}
	if (L -> length >= L -> listsize) {
		base = (EleType *)realloc(L -> elem, (L -> listsize + 10) * sizeof(EleType));
		L -> elem = base;
		L -> listsize = L -> listsize + 100;
	}
	insertPer = &(L -> elem[i - 1]);
	for (p = &(L -> elem[L -> length - 1]); p >= insertPer; p --) {
		*(p + 1) = *p;
	}
	*insertPer = item;
	L -> length ++;
}

void delElem(sqlist *L, int i)
{
	EleType *delItem, *p;
	if (i < 1 || i > L -> listsize) {
		cout << "delete error!" << endl;
	}
	delItem = &(L -> elem[i - 1]);
	p = &(L -> elem[L -> length - 1]);
	for (++ delItem; delItem <= p; delItem ++) {
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
	cout << "list is :" << endl;
	for (i = 0; i < L.length; i ++) {
		cout << L.elem[i] << " ";
	}
	cout << endl;
	delElem(&L, 12);
	cout << "delete list is :" << endl;
	for (i = 0; i < L.length; i++) {
		cout << L.elem[i] << " ";
	}
	cout << endl;
	return 0;
}
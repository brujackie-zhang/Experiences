#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
}LNode, *LinkList;

LinkList CreatLinkList(int n)
{
	LinkList p, r, list = NULL;
	ElemType e;
	int i;
	for (i = 1; i <= n; i ++) {
		printf("please input number:\n");
		scanf("%d", &e);
		p = (LinkList)malloc(sizeof(LNode));
		p -> next = NULL;
		p -> data = e;
		if (! list) {
			list = p;
		} else {
			r -> next = p;
		}
		r = p;
	}
	return list;
}

void insertLinkList(LinkList *list, LinkList q, ElemType e)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	p -> data = e;
	if (! *list) {
		*list = p;
		p -> next = NULL;
	} else {
		p -> next = q -> next;
		q -> next = p;
	}
}
 
void delLinkList(LinkList *list, LinkList q)
{
	LinkList r;
	if (q == *list) {
		*list = q -> next;
		free(q);
	} else {
		for (r = *list; r -> next != q; r = r -> next);
		if (r -> next != NULL) {
			r -> next = q -> next;
			free(q);
		}
	}
}

void destoryLinkList(LinkList *list)
{
	LinkList p, q;
	p = *list;
	while (p) {
		q = p -> next;
		free(q);
		p = q;
	}
	*list = NULL;
}

int main()
{
	LinkList l, q;
	int e, i;
	q = l = CreatLinkList(1);
	scanf("%d", &e);
	while (e) {
		insertLinkList(&l, q, e);
		q = q -> next;
		scanf("%d", &e);
	}
	q = l;
	printf("\nLinkList content is :\n");
	while (q) {
		printf("%d ", q -> data);
		q = q -> next;
	}
	q = l;
	printf("\ndelete LinkList 5 is:\n");
	for (i = 0; i < 4; i ++) {
		if (q == NULL) {
			printf("\nThe LinkList length is small!\n");
		}
		q = q -> next;
	}
	delLinkList(&l, q);
	q = l;
	while (q) {
		printf("%d ", q -> data);
		q = q -> next;
	}
	destoryLinkList(&l);
}
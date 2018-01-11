#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;
typedef struct QNode {
	ElemType data;
	struct QNode *next;
} QNode, *QuenueLink;
typedef struct {
	QuenueLink front;
	QuenueLink rear;
} QLinkList;

void initQLinkList(QLinkList *Q)
{
	Q -> front = Q -> rear = (QuenueLink)malloc(sizeof(QNode));
	if (! Q -> front) exit(0);
	Q -> front = Q -> rear = NULL;
}

void insertQuenue(QLinkList *Q, ElemType e)
{
	QuenueLink p;
	p = (QuenueLink)malloc(sizeof(QNode));
	if (! Q -> front) exit(0);
	p -> data = e;
	p -> next = NULL;
	Q -> rear -> next = p;
	Q -> rear = p;
}

void DeleteQuenue(QLinkList *Q, ElemType *e)
{
	QuenueLink p;
	if (Q -> front == Q -> rear) {
		printf("quenue full!\n");
	}
	p = Q -> front -> next;
	*e = p -> data;
	Q -> front -> next = p -> next;
	if (Q -> rear == p) {
		Q -> rear = Q -> front;
	}
	free(p);
}

void destoryQuenue(QLinkList *Q)
{
	while (Q -> front) {
		Q -> rear = Q -> front -> next;
		free(Q -> front);
		Q -> front = Q -> rear;
	}
}

int main()
{
	ElemType e;
	QLinkList Q;
	initQLinkList(&Q);
	printf("Please input a string:\n");
	scanf("%c", &e);
	while (e != '@') {
		insertQuenue(&Q, e);
		scanf("%c", &e);
	}
	printf("The quenue is:\n");
	while (Q.front != Q.rear) {
		DeleteQuenue(&Q, &e);
		printf("%c ", e);
	}
	printf("\n");
	destoryQuenue(&Q);
}
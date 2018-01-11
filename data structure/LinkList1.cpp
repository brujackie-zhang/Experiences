#include<iostream>
#include<cstdlib>
using namespace std;

typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
}LNode, *LinkList;

LinkList CreateLinkList(int n)
{
	LinkList p, q, list = NULL;
	ElemType e;
	for (int i = 1; i <= n; i ++) {
		cout << "Please input number:" << endl;
		cin >> e;
		p = (LinkList)malloc(sizeof(LNode));
		p -> data = e;
		p -> next = NULL;
		if (! list) {
			list = p;
		} else {
			q -> next = p;
		}
		q = p;
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

void deleteLinkList(LinkList *list, LinkList q)
{
	LinkList p;
	if (q == *list) {
		*list = q -> next;
		free(q);
	} else {
		for (p = *list; p -> next != q; p = p -> next);
		if (p -> next != NULL) {
			p -> next = q -> next;
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
		free(p);
		p = q;
	}
	*list = NULL;
}
// 输入一个单向链表，输出该链表中倒数第K 个节点，链表的倒数第0个节点为链表的尾指针
int main()
{
	LinkList list, q;
	ElemType e;
	list = CreateLinkList(1);
	q = list;
	cin >> e;
	while (e) {
		insertLinkList(&list, q, e);
		q = q -> next;
		cin >> e;
	}
	q = list;
	cout << endl << "The LinkList content is:" << endl;
	while (q) {
		cout << q -> data << " ";
		q = q -> next;
	}
	q = list;
	cout << endl << "delete fifth element :" << endl;
	for (int i = 0; i < 4; i ++) {
		if (q == NULL) {
			cout << "LinkList is short!" << endl;
		}
		q = q -> next;
	}
	deleteLinkList(&list, q);
	q = list;
	while (q) {
		cout << q -> data << " ";
		q = q -> next;
	}

	destoryLinkList(&list);

	return 0;
}
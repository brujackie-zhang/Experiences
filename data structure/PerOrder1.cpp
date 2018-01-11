#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild, *rchild;
}*BiTree;

void CreateBiTree(BiTree *T)
{
	ElemType e;
	scanf("%c", &e);
	if (e == ' ') {
		*T = NULL;
	} else {
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T) -> data = e;
		CreateBiTree(&((*T) -> lchild));
		CreateBiTree(&((*T) -> rchild));
	}
}

void visit(ElemType e, int level)
{
	if (e == 'D') {
		printf("%c is %d level!\n", e, level);
	}
}

void PerOrder(BiTree T, int level)
{
	if (T) {
		visit(T -> data, level);
		PerOrder(T -> lchild, level + 1);
		PerOrder(T -> rchild, level + 1);
	}
}

int main()
{
	BiTree T;
	CreateBiTree(&T);
	PerOrder(T, 1);
}
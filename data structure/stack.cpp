#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100
#define STACK_INCREMENT 10

typedef char ElemType;
typedef struct {
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

void initStack(sqStack *s)
{
	s -> base = (ElemType *)malloc(s -> stackSize * sizeof(ElemType));
	s -> top = s -> base;
	s -> stackSize = MAX_STACK_SIZE;
}

void push(sqStack *s, ElemType e)
{
	if (s -> top - s -> base >= s -> stackSize) {
		printf("stack full!\n");
		s -> base = (ElemType *)realloc(s -> base,(s -> stackSize + STACK_INCREMENT) * sizeof(ElemType));
		s -> top = s -> base + s -> stackSize;
		s -> stackSize = s -> stackSize + STACK_INCREMENT;
	} else {
		*(s -> top) = e;
		s -> top ++;
	}
}

void pop(sqStack *s, ElemType *e)
{
	if (s -> top == s -> base) {
		printf("stack null!\n");
	} else {
		-- s -> top;
		*e = *(s -> top);
	}
}

void clearStack(sqStack *s)
{
	s -> top = s -> base; 
}

void destoryStack(sqStack *s)
{
	free(s -> base);
	s -> base = s -> top = NULL;
	s -> stackSize = 0;
}

int lengthStack(sqStack *s)
{
	return (s -> top - s -> base);
}

int main()
{
	ElemType e;
	sqStack s;

	int len, sum = 0;
	initStack(&s);
	scanf("%c", &e);
	while (e != '#') {
		push(&s, e);
		scanf("%c", &e);
	}

	len = lengthStack(&s);
	for (int i = 0; i < len; i ++) {
		pop(&s, &e);
		sum += (e - 48) * pow(2, i);
	}
	printf("sum is:%d\n", sum);
	destoryStack(&s);

	return 0;
}
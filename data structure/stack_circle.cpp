#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_SIZE 100
#define INC 20

typedef struct {
	char *base;
	char *top;
	int stackSize;
} stack;

void initStack(stack *s)
{
	s -> base = (char *)malloc(s -> stackSize * sizeof(char));
	s -> top = s -> base;
	s -> stackSize = MAX_SIZE;
}

void push(stack *s, char e)
{
	if (s -> top - s -> base >= s -> stackSize) {
		printf("stack full!\n");
		s -> base = (char *)realloc(s -> base, (s -> stackSize + INC) * sizeof(char));
		s -> top = s -> stackSize + s -> base;
		s -> stackSize = s -> stackSize + INC;
	} else {
		*(s -> top) = e;
		s -> top ++;
	}

}

void pop(stack *s, char *e)
{
	if (s -> base == s -> top) {
		printf("stack null!\n");
	} else {
		-- s -> top;
		*e = *(s -> top);
	}
}

int lengthStack(stack *s)
{
	return (s -> top - s -> base);
}

void destoryStack(stack *s)
{
	free(s -> base);
	s -> base = s -> top = NULL;
	s -> stackSize = 0;
}

int main()
{
	stack s;
	char e;
	int sum = 0;
	initStack(&s);
	scanf("%c", &e);
	while (e != '#') {
		push(&s, e);
		scanf("%c", &e);
	}
	int len = lengthStack(&s);

	for (int i = 0; i < len; i ++) {
		pop(&s, &e);
		sum += (e - 48) * pow(2, i);
	}
	printf("sum:%d\n", sum);
	destoryStack(&s);
}
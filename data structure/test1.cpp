#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length;

void findCombination(int n,int m,int *flag)
{
	if(n < 1 || m < 1)
		return;
	if(n > m)
		n = m;
	if(n == m)
	{
		flag[n-1] = 1;
		for(int i=0;i<length;i++)
		{
			if(flag[i] == 1)
				printf("%d\t",i+1);
			printf("\nflag%d:%d", i,flag[i]);
		}
		printf("\n");
		flag[n-1] = 0;
	}
	flag[n-1] = 1;
	findCombination(n-1,m-n,flag);
	flag[n-1] = 0;

	findCombination(n-1,m,flag);
}

int main()
{
	int n, m;
	scanf("%d%d",&n,&m);
	length = n;
	int *flag = (int*)malloc(sizeof(int)*length);
	findCombination(n,m,flag);
	free(flag);
	return 0;
}
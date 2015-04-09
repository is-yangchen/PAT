#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1002

int flag[MAX_SIZE];
int data[MAX_SIZE][MAX_SIZE];

int main()
{
	int N,L,K,num,i,j,tmp,p,q,total;
	int list[MAX_SIZE];
	scanf("%d%d",&N,&L);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&num);
		for(j=0;j<num;j++)
		{
			scanf("%d",&tmp);
			data[tmp][0]++;
			data[tmp][data[tmp][0]] = i;
		}
	}
	scanf("%d",&K);
	for(i=0;i<K;i++)
	{
		scanf("%d",&tmp);
		for(j=1;j<=N;j++){ flag[j] = 0;list[j]=0;}
		flag[tmp] = 1;
		for(j=0;j<L;j++)
		{
			for(p=1;p<=N;p++)
			if (flag[p])
			{
				for(q=1;q<=data[p][0];q++)
				list[data[p][q]] = 1;
			}
			for(p=1;p<=N;p++)
			if (list[p]) flag[p] =1;
		}
		total = 0;
		for(j=1;j<=N;j++) total += flag[j];
		printf("%d\n",total-1);
	}
	return 0;
}
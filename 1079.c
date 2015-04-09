//1079. Total Sales of Supply Chain (25)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100002
int father[MAX_SIZE];
int amount[MAX_SIZE];
int layer[MAX_SIZE];
double Count[MAX_SIZE];
int CalLayer(int k)
{
	if (layer[k]!=-1) 
		return layer[k];
	else
		return CalLayer(father[k])+1;
}

int main()
{
	int N,i,j,tmp,m,lay,child;
	double price,rate,tmpP,total;
	scanf("%d%lf%lf",&N,&price,&rate);
	for (i=0;i<N;i++)
	{
		father[i] = 0;
		amount[i] = 0;
		layer [i] =-1;
		if (i==0)  Count[i] = price;
		else Count[i] = Count[i-1] * (1+rate/100);
	}
	layer[0] = 0;
	for (i=0;i<N;i++)
	{
		scanf("%d",&m);
		if (m>0)
		{
			for (j=0;j<m;j++)
			{
				scanf("%d",&child);
				father[child] = i;
			}
		}
		else
		{
			scanf("%d",&amount[i]);
		}
	}
	total = 0.0;
	for (i=1;i<N;i++)
	{
		layer[i] = CalLayer(i);
	}
	for (i=0;i<N;i++)
	if (amount[i] != 0)
	{
		total += Count[layer[i]] * amount[i];
	}
	printf("%0.1lf",total);
	return 0;
}
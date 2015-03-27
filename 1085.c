#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100002
int data[MAX_SIZE];

int cmp (const void *a,const void *b)
{
	return *(int *)a- *(int *)b;
}
int main()
{
	int N,p,min,max,len,i;
	scanf("%d%d",&N,&p);
	for (i=0;i<N;i++)
	scanf("%d",&data[i]);
	qsort(data,N,sizeof(data[0]),cmp);
	min=0;max=0;len = 1;
	while(max<N)
	{
		if ((p>data[max]/data[min])||((p==data[max]/data[min])&&(data[max]%data[min]==0)))
		{
			if (max+1-min>len) len = max+1-min;
			max++;
		}
		else min++;
	}
	printf("%d",len);
	return 0;
}
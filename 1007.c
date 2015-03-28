#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10002

int main()
{
	long data[MAX],total[MAX];
	long i,j,n,k,minnum=1,min,max,n1=0,n2=1;
	scanf("%ld",&k);
	data[0]=0;total[0]=0;
	for (i=1;i<=k;i++)
	{
		scanf("%ld",&data[i]);	
		total[i] = total[i-1] + data[i];
	}
	min = data[1]+1;
	max = data[1]-1;
	for (i=2;i<=k;i++)
	{
		if (total[i-1]<min)
			{
			min = total[i-1];
			minnum = i-1;
			}
		else
		if (total[i-1]-total[minnum]>max)
			{
				max = total[i-1]-total[minnum];
				n1 = minnum;
				n2 = i-1;
			}
		//printf("%ld %ld\n",min,minnum);
	}
	if (total[n2]-total[n1]>=0)
		printf("%ld %ld %ld",total[n2]-total[n1],data[n1+1],data[n2]);
	else
		printf("%ld %ld %ld",0,data[1],data[k]);
	return 0;
}

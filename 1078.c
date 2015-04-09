//1078. Hashing (25)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_SIZE 10008
int flag[MAX_SIZE];
int data[MAX_SIZE];
void init()
{
	int k,temp;
	for(k=0;k<MAX_SIZE;k++) {flag[k]=1;data[k]=0;}
	flag[0]=0;flag[1]=0;
	k=2;
	while (k<MAX_SIZE)
	{
		temp = k*2;
		while (temp<MAX_SIZE)	{flag[temp]=0;temp += k;}
		k++;
		while ((k<MAX_SIZE)&&(!flag[k])) k++;
	}
}

int main()
{
	int i,j,k,M,N,tmp;
	init();
	scanf("%d %d",&M,&N);
	while (!flag[M]) M++;
	for (i=0;i<N;i++)
	{
		scanf("%d",&k);
		j=0;tmp=(k+j*j)%M;
		while ((j<M)&&(data[tmp]))
		{
			j++;
			tmp=(k+j*j)%M;
		}
		if (j>=M) printf("-");
		else {	printf("%d",tmp);data[tmp]=1;}
		if (i<N-1) printf(" ");
	}
	return 0;
}
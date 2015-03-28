#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 2002
char ID[MAX][8];
int data[MAX][5];
int rank[MAX][4];

void Qsort(int first,int last,int k)
{
	int i,j;
	int x[5];
	if(first<last)
	{
		i=first;j=last;
		x[0]=data[first][0];
		x[1]=data[first][1];
		x[2]=data[first][2];
		x[3]=data[first][3];
		x[4]=data[first][4];
		while(i<j)
		{
			while ((i<j)&&(data[j][k]-x[k]<0))
			j--;
			if (i<j) {
				data[i][0]=data[j][0];
				data[i][1]=data[j][1];
				data[i][2]=data[j][2];
				data[i][3]=data[j][3];
				data[i][4]=data[j][4];
				i++;
			}
			while ((i<j)&&(data[i][k]-x[k]>=0))
			i++;
			if (i<j) {
				data[j][0]=data[i][0];
				data[j][1]=data[i][1];
				data[j][2]=data[i][2];
				data[j][3]=data[i][3];
				data[j][4]=data[i][4];
				j--;
			}	
		}
		data[i][0]=x[0];
		data[i][1]=x[1];
		data[i][2]=x[2];
		data[i][3]=x[3];
		data[i][4]=x[4];	
		Qsort(first,i-1,k);
		Qsort(i+1,last,k);
	}
}

int main()
{
	int n,m,i,j,ii,flag,pick,max;
	char xID[8];
	scanf("%d %d",&n,&m);
	for (i=1;i<= n;i++)
	{
		scanf("%s %d %d %d",&ID[i],&data[i][1],&data[i][2],&data[i][3]);
		data[i][0]=data[i][1]+data[i][2]+data[i][3];
		data[i][4]=i;
	}
	for (i=0;i<4;i++)
	{
		Qsort(1,n,i);
		for (j=1;j<=n;j++)
		{
			rank[data[j][4]][i]=j;
			if ((j!=1)&&(data[j][i]==data[j-1][i]))
				rank[data[j][4]][i]=rank[data[j-1][4]][i];
		}
		//for (ii=1;ii<=n;ii++)
		{
			//printf("%d %d %d %d %d\n",data[ii][0],data[ii][1],data[ii][2],data[ii][3],data[ii][4]);
			//printf("%d\n",rank[ii][i]);
		}
	}
	
	for (i=0;i<m;i++)
	{
		scanf("%s",&xID);
		flag = 1;
		for (j=1;j<=n;j++)
		if (strcmp(ID[j],xID)==0) {
			max=rank[j][0];pick=0;
			if (rank[j][1]<max) {max=rank[j][1];pick=1;}
			if (rank[j][2]<max) {max=rank[j][2];pick=2;}
			if (rank[j][3]<max) {max=rank[j][3];pick=3;}
			printf("%d ",max);
			if (pick==0) printf("A\n");
			if (pick==1) printf("C\n");
			if (pick==2) printf("M\n");
			if (pick==3) printf("E\n");
			flag =0;
			break;
		}
		if (flag) printf("N/A\n");
	}
	return 0;
}

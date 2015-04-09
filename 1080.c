//排序
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define STU_SIZE 40002
#define SCH_SIZE 102

struct Student
{
	int number;
	int Ge;
	int Gi;
	int total;
	int choice[6];
}Stu[STU_SIZE];

int enroll[SCH_SIZE][STU_SIZE];
int quota[SCH_SIZE];
int cmp(const void* a,const void* b)
{
	struct Student *c =(struct Student*)a;
	struct Student *d =(struct Student*)b;
	if (c->total != d->total) return d->total - c->total;
	else return d->Ge - c->Ge;
}
int cmp1(const void* a,const void* b)
{
	return Stu[*(int *)a].number - Stu[*(int *)b].number;
}

void Qsort(int first,int last,int k)
{
	int i,j,l1,l2;
	int xNumber;
	if(first<last)
	{
		i=first;j=last;
		xNumber = enroll[k][first];
		while(i<j)
		{
			while ((i<j)&&(enroll[k][j]>=xNumber))
			j--;
			if (i<j) {
				enroll[k][i]=enroll[k][j];
				i++;
			}
			while ((i<j)&&(enroll[k][i]<xNumber))
			i++;
			if (i<j) {
				enroll[k][j]=enroll[k][i];
				j--;
			}
		}
		enroll[k][i]=xNumber;
		Qsort(first,i-1,k);
		Qsort(i+1,last,k);
	}
}

int main()
{
	int N,M,K,i,j;
	struct Student * tmp;
	scanf("%d %d %d",&N,&M,&K);
	for(i=0;i<M;i++) 
	{	scanf("%d",&quota[i]);
		enroll[i][0] = 0;
	}
	for(i=0;i<N;i++)
	{	
		scanf("%d %d",&Stu[i].Ge,&Stu[i].Gi);
		Stu[i].number = i;
		Stu[i].total = Stu[i].Ge+Stu[i].Gi;
		for(j=0;j<K;j++) scanf("%d",&Stu[i].choice[j]);
	}
	qsort(Stu,N,sizeof(Stu[0]),cmp);
	for(i=0;i<N;i++)
	{
		for(j=0;j<K;j++)
		{
			tmp = &Stu[i];
			if ((enroll[tmp->choice[j]][0]<quota[tmp->choice[j]])||	
				((tmp->total == Stu[enroll[tmp->choice[j]][enroll[tmp->choice[j]][0]]].total)&&
				 (tmp->Ge == Stu[enroll[tmp->choice[j]][enroll[tmp->choice[j]][0]]].Ge)))
			{
				enroll[tmp->choice[j]][0]++;
				enroll[tmp->choice[j]][enroll[tmp->choice[j]][0]] = i;
				break;
			}
		}
	}
	for(i=0;i<M;i++)
	{
		if (enroll[i][0]==0)  printf("\n");
		else
		{
		qsort(&enroll[i][1],enroll[i][0],sizeof(enroll[i][0]),cmp1);
		for(j=1;j<enroll[i][0];j++)
			printf("%d ",Stu[enroll[i][j]].number);
		printf("%d\n",Stu[enroll[i][enroll[i][0]]].number);
		}
	}
	return 0;
}
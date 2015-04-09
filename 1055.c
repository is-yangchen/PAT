#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100005

struct Person
{
	char Name[10];
	int age;
	int worth;
}data[MAX_SIZE];

int pick[MAX_SIZE];

int cmp(const void * a,const void * b)
{
	struct Person *x = (struct Person*)a;
	struct Person *y = (struct Person*)b;
	if (x->worth != y->worth) return y->worth - x->worth;
	if (x->age != y->age)  	  return x->age - y->age;
	return strcmp(x->Name,y->Name);
}
int cmp1(const void *a, const void *b)
{
	struct Person x = (struct Person)data[*(int *)a];
	struct Person y = (struct Person)data[*(int *)b];
	if (x.worth != y.worth) return y.worth - x.worth;
	if (x.age != y.age) return x.age - y.age;
	return strcmp(x.Name,y.Name);
}
int main()
{
	int N,K,M,min,max,kk;
	int i,j,len,pick_num=0;
	int ageCount[202];
	for(i=0;i<202;i++) ageCount[i]=0;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++)
	{
		scanf("%s %d %d",&data[i].Name,&data[i].age,&data[i].worth);
	}
	qsort(data,N,sizeof(data[0]),cmp);
	for(i=0;i<N;i++)
	{
		if (++ageCount[data[i].age]<101)
		{
			pick[pick_num++] = i;
		}
	}
	for(i=1;i<=K;i++)
	{
		scanf("%d %d %d",&M,&min,&max);
		len=0;
		printf("Case #%d:\n",i);
		for(j=0;j<pick_num;j++)
		{
			kk = pick[j];
			if ((data[kk].age>=min)&&(data[kk].age<=max)&&(len<M))
			{
				printf("%s %d %d\n",data[pick[j]].Name,data[pick[j]].age,data[pick[j]].worth);
				len++;
			}
		}
		if (len == 0 ) printf("None\n");
	}
	return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 102

struct Student
{
	char Name[11];
	char ID[11];
	int grade; 
}Stu[MAX_SIZE];

int cmp(const void* a, const void* b)
{
	return (*(struct Student *)b).grade - (*(struct Student *)a).grade;
}
int main()
{
	int N,i,grade1,grade2,flag=0;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%s %s %d",&Stu[i].Name,&Stu[i].ID,&Stu[i].grade);
	}
	scanf("%d %d",&grade1,&grade2);
	qsort(Stu,N,sizeof(Stu[0]),cmp);
	for(i=0;i<N;i++)
	if ((Stu[i].grade>=grade1)&&(Stu[i].grade<=grade2))
	{
		printf("%s %s\n",Stu[i].Name,Stu[i].ID);
		flag = 1;
	}
	if (!flag) printf("NONE");
	return 0;
}
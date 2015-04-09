//简单记录处理+快排解决
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 10005

struct User
{
	char usr_id[8];
	int score[8];
	int flag[8];
	int test[8];
	int total_score;
	int perfect_num;
	int rank;
	int flag_shown;
}data[MAX_SIZE];


int p[8];

int cmp(const void* a,const void* b)
{
	struct User *x = (struct User*)a;
	struct User *y = (struct User*)b;
	if (x->total_score != y->total_score) return y->total_score - x->total_score;
	if (x->perfect_num != y->perfect_num) return y->perfect_num - x->perfect_num;
	return strcmp(x->usr_id,y->usr_id);
}
int main()
{
	int N,K,M,i,j;
	int tmp_id,tmp_score,pro_id;
	char tmp_uid[8];
	scanf("%d %d %d",&N,&K,&M);
	for(i=1;i<=N;i++)
	{
		data[i].perfect_num= 0;
		data[i].flag_shown = 0;
		data[i].total_score = 0;
		for(j=1;j<=5;j++)
		{
			data[i].score[j] = 0;
			data[i].flag[j]  = 0;
			data[i].test[j]  = 0;
		}
	}
	
	for(i=1;i<=K;i++)
		scanf("%d",&p[i]);
	
	for(i=0;i<M;i++)
	{
		scanf("%s %d",&tmp_uid,&pro_id);
		scanf("%d",&tmp_score);
		tmp_id = atoi(tmp_uid);
		stpcpy(data[tmp_id].usr_id , tmp_uid);
		if ((tmp_score >= data[tmp_id].score[pro_id])&&(tmp_score >= 0))
		{
			data[tmp_id].total_score = data[tmp_id].total_score + tmp_score - data[tmp_id].score[pro_id];
			data[tmp_id].score[pro_id] = tmp_score;
			if ((data[tmp_id].score[pro_id] == p[pro_id])&&(data[tmp_id].flag[pro_id] != 1))
			{
				data[tmp_id].perfect_num++;
				data[tmp_id].flag[pro_id] = 1;
			}
			//if (data[tmp_id].score[pro_id]>-1)
			{
				data[tmp_id].flag_shown = 1;
				data[tmp_id].test[pro_id] = 1;
			}
		}
		if ((tmp_score == -1)&&(data[tmp_id].test[pro_id] ==0)) data[tmp_id].test[pro_id] = -1;
	}
	qsort(&data[1],N,sizeof(data[1]),cmp);
	data[1].rank = 1;
	for(i=2;i<=N;i++)
	{
		if (data[i].total_score == data[i-1].total_score) data[i].rank = data[i-1].rank;
		else data[i].rank = i;
	}
	for(i=1;i<=N;i++)
	{
		if (data[i].flag_shown)
		{	
			printf("%d %s %d",data[i].rank,data[i].usr_id,data[i].total_score);
			for(j=1;j<=K;j++)
			{
				if (data[i].test[j]==1) printf(" %d",data[i].score[j]);
				if (data[i].test[j]==0) printf(" -");
				if (data[i].test[j]==-1) printf(" 0");
			}
			printf("\n");
		}
	}
	return 0;
}

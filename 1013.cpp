//求图的连通分支个数，需要修复的路就是连通分支个数-1
#include <iostream>
using namespace std;

#define MAX 1000
int map[MAX+1][MAX+1];
int visited[MAX+1];
int N,M,K;

void dfs(int start)
{
	int i;
	visited[start] = true;
	for(i=1;i<=N;i++)
	if ((!visited[i])&&(map[start][i]==1))
	{
		//printf("i=%d\n",i);
		dfs(i);
	}
}
void init()
{
	int i,j,a,b;
	scanf("%d %d %d",&N,&M,&K);
	for(i=1;i<=N;i++)
	for(j=1;j<=N;j++)
	map[i][j] = 0;
	for(i=0;i<M;i++)
	{
		scanf("%d %d",&a,&b);
		map[a][b] = 1;
		map[b][a] = 1;
	}
}

int main()
{
	int i,j,k,lost,total;
	
	init();
	for(i=0;i<K;i++)
	{
		scanf("%d",&lost);
		total = 0;
		for(j=1;j<=N;j++) visited[j] = false;
		visited[lost] = true;
		for(j=1;j<=N;j++)
		if (!visited[j])
		{
			dfs(j);
			total++;
		}
		printf("%d\n",total-1);
	}
	return 0;
}

//Dijkstra求最短路径，dfs求个数
#include <iostream>
using namespace std;

#define MAX 502
#define MAX_INT (1<<31)-1

int* num;
bool* visited;
int* dist;				//距离
int* weight;			//权重，此处为最大team数
int map[MAX][MAX];
int N,M,C1,C2,cnt = 0,maxNum=0;

void dfs(int index, int teams)
{
	int i;
	teams += num[index];
	//printf("teams=%d\n",teams);
	if (index==C2)
	{
		cnt++;
		if (teams>maxNum) maxNum = teams;
	}
	else
	{
		for(i=0;i<N;i++)
		{
			if((i!=index) && (dist[i]-dist[index]==map[i][index]))
				dfs(i,teams);
		}
	}
}

void Dijkstra(int* dist,int* weight,int* num,bool* visited)
{
	int i,j,u,min;
	for(i=0;i<N;i++)
	{
		if(map[C1][i])
		{	
			dist[i] = map[C1][i];
			//if (dist[i]<MAX_INT)	weight[i] = num[C1]+num[i];
			//if (i==C2) cnt++;
		}
	}
	dist[C1] = 0;
	visited[C1] = true;
	for(i=1;i<=N-1;i++)
	{
		min = MAX_INT;
		u = C1;
		for(j=0;j<N;j++)
		{ 
			if((!visited[j])&&(dist[j]<min))
			{
				u = j;
				min = dist[j];
			}
		}
		visited[u] = true;
		for(j=0;j<N;j++)
		if (!visited[j])
		{
			if ((map[u][j]<MAX_INT)&&(dist[j]-dist[u]>map[u][j]) )
			{	dist[j] = dist[u]+map[u][j]; 
				//if (j==C2)	cnt = 1;
				//if (weight[u]+num[j]>weight[j]) weight[j] = weight[u]+num[j];
			}
			else if ((dist[j]-dist[u]==map[u][j])) 
					{	//if (j==C2)cnt++;			
						//if (weight[u]+num[j]>weight[j]) weight[j] = weight[u]+num[j];
					}
		}
	}
}
int main()
{
	int a,b,len;
	int i,j;
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	num = (int*)malloc(sizeof(int)*N);
	dist = (int*)malloc(sizeof(int)*N);
	weight = (int*)malloc(sizeof(int)*N);
	visited = (bool*)malloc(sizeof(bool)*N);
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	{
		//if (i!=j) map[i][j] = MAX_INT;	else
		map[i][j]=MAX_INT;
	}
	for(i=0;i<N;i++) {	scanf("%d",&num[i]);dist[i] = MAX_INT;weight[i] = 0;visited[i] = false;}
	for(i=0;i<M;i++) {	scanf("%d %d %d",&a,&b,&len);map[a][b]=len;map[b][a]=len;}
	Dijkstra(dist,weight,num,visited);
	//for(i=0;i<N;i++)
	//printf("dist[%d]=%d",i,dist[i]);
	dfs(C1,0);
	printf("%d %d",cnt,maxNum);
	//for(i=0;i<N;i++)
	//printf("%d\t",dist[i]);
	return 0;
}

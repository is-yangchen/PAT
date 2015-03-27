//背包问题
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[10005][105];
int coins[10005];
vector<int> path;
bool cmp(const int& x,const int& y)
{
	return x > y;
}
int main()
{
	int N,M,i,j;
	cin >> N >> M;
	for(i=1;i<=N;i++)
		cin>>coins[i];
	sort(coins+1,coins+N+1,cmp);
	//memset(dp,0,sizeof(dp));
	for(i=0;i<=N;i++)
	for(j=0;j<=M;j++)
	dp[i][j] = 0;
	for(i=1;i<=N;i++)
	for(j=1;j<=M;j++)
	{
		if ((coins[i]>j)||(dp[i-1][j-coins[i]]+coins[i]<dp[i-1][j]))
			dp[i][j] = dp[i-1][j];
		else
		{
			dp[i][j] = dp[i-1][j-coins[i]] + coins[i];
		}
	}
	
	if (M != dp[N][M]) printf("No Solution\n");
	else
	{
		while(M>0)
		{
			if (dp[N-1][M-coins[N]] == M-coins[N])
			{
					path.push_back(coins[N]);
					M -=coins[N];
			}
			N--;
		}
		vector<int>::iterator iter;
		for(iter=path.begin();iter!=path.end();iter++)
		{
			if (iter == path.begin()) printf("%d",*iter);
			else printf(" %d",*iter);
		}
	}
	//system("pause");
	return 0;	
}
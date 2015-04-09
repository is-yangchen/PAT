//先求联通子图，然后判断每个联通子图是否符合要求，符合要求的找他们的老大
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 1002*2 //26*26*26
#define Num_MAX 1002
struct Call
{
	int n1;
	int n2;
	int time;
};
Call* calls;
int visited[MAX];
int groups[MAX];
bool links[MAX][MAX];
vector<string> records;
map<int,int> Gangs[MAX];
map<int,int>::iterator iter;
int NoG; //Num of Gangs
typedef struct gang
{
	int index;
	int size;
}gang;
vector<gang> result;

void init()
{
	int i,j;
	for(i=0;i<MAX;i++)
	{
		visited[i] = 0;
		for(j=0;j<MAX;j++)
		links[i][j] = false;
	}
}

void dfs(int x)
{
	int i;
	visited[x] = 1;
	groups[x] = NoG;
	Gangs[NoG].insert(pair<int,int>(x,0));
	for(i=0;i<records.size();i++)
	if ((!visited[i])&& (links[x][i]))
	dfs(i);
}

bool SortBySize(const map<int,int> &x, map<int,int> &y)
{
	return x.size() - y.size();
}

bool SortByValue(const map<int,int> &x, map<int,int> &y)
{
	return x.begin()->second - y.begin()->second;
}

bool cmp(const gang& x, const gang& y)
{
	return records[x.index] < records[y.index];
}
int main()
{
	int N,K,i,j,total,maxValue,maxIndex,totalValue;
	string tmp1,tmp2;
	gang tmpgang;
	//scanf("%d %d",&N,&K);
	cin >> N >> K;
	calls = (Call*)malloc(sizeof(struct Call)*(N+1));
	init();
	for(i=0;i<N;i++)
	{
		//scanf("%s %s %d",&tmp1,&tmp2,&calls[i].time);
		cin >> tmp1 >> tmp2 >> calls[i].time;
		for(j=0;j<records.size();j++)
		if (records[j] == tmp1) break;
		//if (strcmp(records[j],tmp1)==0) break;
		calls[i].n1 = j;
		if (j>=records.size())
		{
			records.push_back(string(tmp1));
		}
		for(j=0;j<records.size();j++)
		if (records[j].compare(tmp2) ==0) break;
		//if (strcmp(records[j],tmp2)==0) break;
		calls[i].n2 = j;
		if (j>=records.size())
		{
			records.push_back(tmp2);
		}
		links[calls[i].n1][calls[i].n2] = true;
		links[calls[i].n2][calls[i].n1] = true;
	}
	NoG = 0;
	for(i=0;i<records.size();i++)
	if (!visited[i])
	{
		
		dfs(i);	
		NoG++;
	}
	for(i=0;i<N;i++)
	{
		j = groups[calls[i].n1];
		//for(j=0;j<NoG;j++)
		{
			for(iter = Gangs[j].begin();iter!=Gangs[j].end();iter++)
			{
			if (calls[i].n1 == iter->first) iter->second += calls[i].time;
			if (calls[i].n2 == iter->first) iter->second += calls[i].time;
			//printf("pair fisrt = %d,second= %d\n",iter->first,iter->second);
			}
		}
	}
	for(j=0;j<NoG;j++)
	{
		if (Gangs[j].size()<=2) continue;
		maxValue = 0;totalValue = 0;
		for(iter = Gangs[j].begin();iter!=Gangs[j].end();iter++)
		{
			if (iter->second > maxValue)
			{
				maxIndex = iter->first;
				maxValue = iter->second;
			}
			totalValue += iter->second;
		}
		//printf("maxValue = %d\n",maxValue);
		if (totalValue>K*2)
		{
			tmpgang.index = maxIndex;
			tmpgang.size  = Gangs[j].size();
			result.push_back(tmpgang);
		}
	}
	printf("%d\n",result.size());
	sort(result.begin(),result.end(),cmp);
	for(i=0;i<result.size();i++)
	{
		//cout << records[result[i].index] << " " << result[i].size << endl;
		printf("%s %d\n",records[result[i].index].c_str(),result[i].size);
	}
	return 0;
}

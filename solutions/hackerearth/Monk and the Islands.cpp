#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
#define pb push_back
using namespace std;
vector<int> v[10000];
queue<int> q;
bool vis[10000];
int level[10000];

int max(int a,int b,int c)
{
	return max(max(a,b),c);
}
int bfs(int n)
{
	//vis[10000]={0};
	//level[10000]={-1};
	memset(vis,0,sizeof(vis));
	memset(level,-1,sizeof(level));
	int i,p;
	q.push(1);
	level[1]=0;
	vis[1]= 1;
	while(!q.empty())
	{
		p= q.front();
		q.pop();
		for(int i=0;i<v[p].size();i++)
		{
			if(vis[v[p][i]]==0)
			{
				q.push(v[p][i]);
				vis[v[p][i]]=1;
				level[v[p][i]] = level[p]+1;
			}
		}
	}

	return level[n];
}
int main(){
	int mm,a,b,i,sol,m,n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		mm = 1;
		for(i = 0;i <m;i++)
		{

			scanf("%d%d",&a,&b);
			mm = max(mm,a,b);
			v[a].pb(b);
			v[b].pb(a);
		}
		sol = bfs(mm);
		printf("%d\n",sol);
	}
}
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[10];
bool vis[10]={0};
void dfs(int ver)
{
	int top,i,
	stack<int> s;
	s.push(ver);
	while(!s.empty())
	{
		
		top = s.top();
		s.pop();
		vis[top]= 1;
		printf("%d",vis[top]);
		for(i=0;i<v[top].size();i++)
		{
			if(vis[v[top][i]]==0)
			{	
				dfs(v[top][i]);

			}
		}
	}
}
int main(){
	int v,e,a,b;
	scanf("%d",&v);
	scanf("%d",&e);
	for(int i=0;i<e;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);

}
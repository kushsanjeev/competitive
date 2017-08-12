#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[10];
bool vis[10]={0};
stack<int > s;
void dfs(int ver)
{
	int i,top;
	s.push(ver);
	while(!s.empty())
	{
		top = s.top();
		s.pop();
		vis[v[top]]= 1;
		printf("%d\n",v[top]);
		for(i=0;i<v[top].size();i++)
		{
			if(vis[v[top][i]]==0)
			{
				vis[v[top][i]] = 1;
				s.push(v[top][i]);
			}
		}
	}
}
int main(){
	int v,e,a,b,i;
	scanf("%d%d",&v,&e);
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	return 0;

}
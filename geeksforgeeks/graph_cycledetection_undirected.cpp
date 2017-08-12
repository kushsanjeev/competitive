#include <iostream>
#include <vector>
using namespace std;
//O(V+Eß)
vector<int> vec[10];
bool vis[10]={0};
bool iscycleUtil(int v,int parent)
{
	vis[v] = true;
	vector<int>::iterator itr;
	for(itr = vec[v].begin();itr!=vec[v].end();itr++)
	{
		if(!vis[*itr])
		{
				if(iscycleUtil(*itr,v))
					return true;
		}

		else if(*itr!=parent)
			return true;
	}
	return false;
}
bool iscycle(int V){
	int u;
	for(u=0;u<V;u++)
	{
		if(!vis[u])
			if(iscycleUtil(u,-1))
				return true;
	}
	return false;
}

int main(){
	int V,i,a,b,edges;
	cin>>V;
	cin>>edges;
	for(i=0;i<edges;i++)
	{
		cin>>a>>b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	if(iscycle(V))
		cout<<"Cycle"<<endl;
	else
		cout<<"Not cycle"<<endl;
	return 0;
}
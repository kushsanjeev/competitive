#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[10];
bool vis[10]={0};
bool rs[10]={0};
bool iscycleutil(int v){
	if(vis[v]==0)
	{
		vis[v]=1;
		rs[v]=1;
		vector<int>::iterator itr;
		for(itr=vec[v].begin();itr!=vec[v].end();itr++)
		{
			if(!vis[*itr]&&iscycleutil(*itr))
				return true;
			else if(rs[*itr])
				return true;
		}
	}
	rs[v] = 0;
	return false;
}
bool iscycle(int V){
	int i;
	for(i=0;i<V;i++)
		if(iscycleutil(i))
			return true;

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
		//vec[b].push_back(a);
	}
	if(iscycle(V))
		cout<<"Cycle"<<endl;
	else
		cout<<"Not cycle"<<endl;
	return 0;
}
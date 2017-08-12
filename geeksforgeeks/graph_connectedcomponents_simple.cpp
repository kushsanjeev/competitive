#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
bool vis[10] = {0};
vector<int> vec1[10];
void DFSUtil(int v)
{
	vis[v] = true;
	cout<<v<<" ";
	vector<int>::iterator itr;
	for(itr = vec1[v].begin();itr!=vec1[v].end();++itr)
		if(!vis[*itr])
			DFSUtil(*itr);
}
void conc(int V){
	for (int v=0; v<V; v++)
    {
        if (vis[v] == false)
        {
            // print all reachable vertices
            // from v
            DFSUtil(v);
 
            cout << "\n";
        }
    }
}
int main(){
	int V,edges,i,a,b;
	cin>>V>>edges;
	for(i=0;i<edges;i++)
	{
		cin>>a>>b;
		vec1[a].push_back(b);
		vec1[b].push_back(a);
	}
	conc(V);
	return 0;
}
#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
bool vis[10] = {0};
vector<int> vec1[10];
void DFSU(int v)
{
    vis[v] = true;
    cout<<v<<" ";
    vector<int> ::iterator itr;
    for(itr = vec1[v].begin();itr!=vec1[v].end();++itr)
        if(!vis[*itr])
            DFSU(*itr);
}
void DFS(int v)
{
    for(int i=1;i<v;i++)
    {
        if(vis[i]==false)
            DFSU(i);
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
    DFS(V);
    return 0;
}
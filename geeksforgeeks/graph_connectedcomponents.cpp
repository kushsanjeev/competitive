// C++ Implementation of Kosaraju's algorithm to print all SCCs
#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
vector<int> vec[10];
vector<int> vec1[10];
stack<int> s;
bool vis[10] = {0};
void dfsu(int v){
	//mark the current node as visited and print it
	vis[v] = true;
	cout<<v<<" ";
	//// Recur for all the vertices adjacent to this vertex
	vector<int>::iterator itr;
	for(itr = vec1[v].begin();itr!=vec1[v].end();++itr)
		if(!vis[*itr])
			dfsu(*itr);


}	

void transpose(int V){
	int v;
	for(v=0;v<V;v++)
	{
	//recus for all the vertices adjacent to this vertex
		vector<int>::iterator itr;
		for(itr = vec[v].begin();itr!=vec[v].end();itr++)
		{
			vec1[*itr].push_back(v);
		}
	}

}
void fillOrder(int v){
	//mark current node as visited and print it
	vis[v]=true;
	//recur for all vertices adjacent to this vertex
	vector<int>::iterator itr;
	for(itr = vec[v].begin();itr!=vec[v].end();itr++)
	{
		if(!vis[*itr])
			fillOrder(*itr);
	}
	//all vertices rechable from v are procesed by now, push v
	s.push(v);
}
void printSCC(int V){
	int i;
	//fill vertices in stack accoring to their finishing time
	for(i=0;i<V;i++)
		if(vis[i]==false)
			fillOrder(i);
	//create a reversed graph
	transpose(V);

	memset(vis,0,sizeof(vis));

	while(s.empty()==false)
	{
		//pop a vertex from stack
		int v = s.top();
		s.pop();
		//print strongly connected components of the poped vertex
		if(vis[v]==false)
		{
			dfsu(v);
			cout<<"\n";
		}


	}


}
int main(){
	int V,edges,i,a,b;
	cin>>V>>edges;
	for(i=0;i<edges;i++)
	{
		cin>>a>>b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	printSCC(V);
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;
vector <int> v[10] ;   //Vector for maintaining adjacency list explained above
    int level[10]; //To determine the level of each node
    bool vis[10];
void bfs(int s) {
    queue <int> q;
    q.push(s);
    level[ s ] = 0 ;  //Setting the level of the source node as 0
    vis[ s ] = true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        pirntf(v[p]);
        for(int i = 0;i < v[ p ].size() ; i++)
        {
            if(vis[ v[ p ][ i ] ] == false)
            {
        //Setting the level of each node with an increment in the level of parent node
                level[ v[ p ][ i ] ] = level[ p ]+1;                 
                 q.push(v[ p ][ i ]);
                 vis[ v[ p ][ i ] ] = true;
         }
            }
    }
}
int main(){
    int ver,e,a,b,i;
    scanf("%d%d",&ver,&e);
    for(i=0;i<e;i++)
    {
        scanf("%d%d",&a,&b);
        v[a].push_back(a);
        v[b].push_back(b);
    }
    bfs(1);
    return 0;
}
 //Mark the node if visited 
    
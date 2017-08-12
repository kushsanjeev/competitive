//MAXN = maximum points in the graph
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 1000
vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1){
                //v is articulation point

                ++children;
            }
        }
    }
    if (p == -1 && children > 1){
        //v is articulation point
        cout<<v<<","<<endl;
        }
}

int main() {
    int n,edges,a,b,i;
    cin>>n>>edges;
    for(i=0;i<edges;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);    
    }
    timer = 0;
    for (int i=0; i<n; ++i)
        used[i] = false;
    dfs (0);
}
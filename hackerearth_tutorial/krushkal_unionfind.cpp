#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

//start of union find algo
//union find algo used to check if the selected node forms a cycle
void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}
//end of union find algo

//start of krushkal
long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;//starting node of the edge
        y = p[i].second.second;//ending node of the edge
        cost = p[i].first;//weight of the edge
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))//checking if they do not form a cycle
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;//return minimum cost of the spanning tree
}
//end of krushkal

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);//sorting the edges according to their weight
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}
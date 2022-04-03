#include<bits/stdc++.h>
//*** Minimum Spanning Tree
using namespace std;
#define pii pair< int , int >

const int N = 1e4 + 5;
bool vis[N];
vector <pii> adj[N];

long long prim(int x)
{
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int y;
    long long minimumCost = 0;
    pii p;
    pq.push(make_pair(0, x));
    while(!pq.empty())
    {
        // Select the edge with minimum weight
        p = pq.top();
        pq.pop();
        x = p.second;
        // Checking for cycle
        if(vis[x] == true)
            continue;
        minimumCost += p.first;
        vis[x] = true;
        for(int i = 0;i < adj[x].size();++i)
        {
            y = adj[x][i].second;
            if(vis[y] == false)
                pq.push(adj[x][i]);
        }
    }
    return minimumCost;
}

int main()
{
    int nodes, edges, x, y;
    long long weight, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        adj[x].push_back(make_pair(weight, y));
        adj[y].push_back(make_pair(weight, x));
    }
    // Selecting 1 as the starting node
    minimumCost = prim(1);
    cout << minimumCost << endl;
    return 0;
}
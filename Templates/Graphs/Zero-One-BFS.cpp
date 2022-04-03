#include<bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define int long long
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
#define F first
#define S second
const int N=3e5+5;
#define inf 1e18

/** 0-1 BFS **/
int const V = 10;
vector< pair< int , int > > edges[V];

void zeroOneBFS(int s)
{
    int dis[V];
    for(long long & di : dis) di = inf;
    deque< int > q;
    dis[s] = 0;
    q.push_back(s);
    while(!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for(int i=0 ; i<edges[v].size() ; i++)
        {
            if(dis[edges[v][i].first] > dis[v] + edges[v][i].second){
                dis[edges[v][i].first] = dis[v] + edges[v][i].second;

                if(edges[v][i].second == 0)
                {
                    q.push_front(edges[v][i].first);
                }
                else{
                    q.push_back(edges[v][i].first);
                }
            }
        }
    }

    for(long long di : dis)
    {
        cout << di << " ";
    }
}
void addEdge(int u , int v , int weight)
{
    edges[u].emplace_back(v , weight);
}



signed main()
{
    addEdge(0, 1, 0);
    addEdge(0, 7, 1);
    addEdge(1, 7, 1);
    addEdge(1, 2, 1);
    addEdge(2, 3, 0);
    addEdge(2, 5, 0);
    addEdge(2, 8, 1);
    addEdge(3, 4, 1);
    addEdge(3, 5, 1);
    addEdge(4, 5, 1);
    addEdge(5, 6, 1);
    addEdge(6, 7, 1);
    addEdge(7, 8, 1);
    int src = 0;//source node
    zeroOneBFS(src);
}


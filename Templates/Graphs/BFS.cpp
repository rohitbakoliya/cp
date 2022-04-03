#include<bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define int long long
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
#define F first
#define S second
const int M = 1000000007;
const int N=3e3+5;
#define inf 1e18
#define eps -1e18

bool vis[N];
vector< int > v[N];
int level[N];
void bfs(int s)
{
    queue< int > q;
//level of src
    level[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(long long i : v[p])
        {
            if(!vis[i]){
                vis[i] = true;
                q.push(i);
                level[i] = level[p] + 1;
            }
        }
    }
}
//FOR MULTI SOURCE BFS INSERT ALL THE SOURCES IN THE QUEUE FIRST THEN APPLY SIMLE BFS.



signed main()
{
    int n ;
    cin >> n;
    while(--n)
    {
        int a , b;
        cin>> a >>b ;
        v[a].pb(b);
        v[b].pb(a);
    }
    int src = 1;
    bfs(src);
}


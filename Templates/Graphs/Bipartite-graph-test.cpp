#include<bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define int long long
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pii pair< int , int >
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define bitcnt(n) __builtin_popcountll(n)
#define setpre(n) cout << fixed << setprecision(n)
#define tr(c) for(auto x : c )cout << x << " ";
#define ol(c , s , e ) for(int pos=s; pos<e ; pos++) cout << c[pos] << " ";
#define inf 2e18;
const int M = 1000000007;
const int N=1e6+5;

//#define local
#ifdef local
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif

//if cycle of odd length found then it is not bipartite

// --------------------------------- COPY FROM HERE -------------
int color[N];
bool vis[N];
vector<int> v[N];
bool dfs(int i, int c){
    vis[i] = 1;
    color[i] = c;
    for(auto x : v[i]){
        if(!vis[x]){
            if(!dfs(x, c ^ 1))
                return false;
        }
        else if(color[x] == color[i])
            return false;
    }
    return true;
}

//----------------------------- COPY TILL HERE ------------- 
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        v[i].clear();
    memset(color, 0 , sizeof color);
    memset(vis, 0 , sizeof vis);
    for(int i=0 ; i<m; i++){
        int l ,r;
        cin >> l >> r;
        v[l].pb(r);
        v[r].pb(l);
    }
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            if(!dfs(i , 0)){
                cout <<  "Suspicious bugs found!\n";
                return ;
            }
        }
    }
    cout <<  "No suspicious bugs found!" << endl;
}
signed main() {
    FAST;
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Int int32_t
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pii pair< int , int >
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define bitcnt(n) __builtin_popcountll(n)
#define setpre(n) cout << fixed << setprecision(n)
#define tr(c) for(auto x : c )cout << x << " ";
#define ol(c, s, e) for(int pos=s; pos<e ; pos++) cout << c[pos] << " ";
#define PI acos(-1l)
const int M = 1000000007;
const int N = 3e5 + 5;
const long long INF = 1e9 + 37;

#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif


bool vis[N];
vector<int> v[N];
//return true if graph contains cycle
bool dfs(int i , int parent){
    vis[i] = 1;
    for(auto x : v[i]){
        if(!vis[x]){
            if(dfs(x , i))
                return true;
        }
        //if back edge found 
        else if(x != parent)
            return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        v[i].clear();
    memset(vis, 0 , sizeof vis);
    for(int i=0 ; i<m; i++){
        int l ,r;
        cin >> l >> r;
        v[l].pb(r);
        v[r].pb(l);
    }
    for(int i=1 ; i<=n ; i++){
        if(!vis[i]){
            if(dfs(i , 0)){
                cout << "YES graph contains cycle\n";
                return ;
            }
        }
    }
    cout<<"NO Graph doesnt contains cycle\n";
}

signed main() {
    FAST;
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
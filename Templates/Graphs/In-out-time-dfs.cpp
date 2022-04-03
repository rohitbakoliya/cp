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
/*
Tutorial : https://www.youtube.com/watch?v=G0N7j-x3YT4&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=12

PROPS:

1) in-time of parent is less than in-time of chilren.
2) out-time of parent is greater than out-time of children.
3) if 2 nodes belongs to same subtree then one of the node is having greater in-time as well as out-time than another.
*/

// ----------------------------- COPY FROM HERE --------------------
bool vis[N];
vector<int> v[N];
int in[N] , out[N];
int timer = 1;
//in out time implementation
void dfs(int i){
    vis[i] = 1;
    in[i] = timer++;
    for(auto x : v[i]){
        if(!vis[x]){
            dfs(x);
        }
    }
    out[i] = timer++;
}

//true if a is parent of b; 
inline bool isAnc(int a, int b){
    return in[b]>=in[a] && out[b]<=out[a];
}
//-------------------------COPY TILL HERE -----------------------------
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

}

signed main() {
    FAST;
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
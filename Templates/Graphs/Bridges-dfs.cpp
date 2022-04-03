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
const int N = 3e3 + 5;
const long long INF = 1e9 + 37;

#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif
//---------------IT IS WRONG IMPLEMENTATION MAY BE ---------------------------



vector<int> v[N];
int in[N] , low[N];
bool vis[N];
int timer = 0;
void dfs(int i , int parent){
    vis[i] = 1;
    in[i] = low[i] = timer;
    timer++;
    for(int x : v[i]){
        if(x == parent) continue;
        if(vis[x]){
            low[i] = min(low[i] , in[x]);
        }
        else{
            dfs(x , i);
            if(low[x] > in[i]){
                cout << i << " -> " << x << " is a brige\n";
            }
            low[i] = min(low[i] , in[x]);
        }
    }
}
void solve(){
   int n, m;
   cin >> n >> m;
   while(m--){
       int a, b;
       cin >> a >> b;
       v[a].pb(b);
       v[b].pb(a);
   }
   dfs(1,-1);
}

signed main() {
    FAST;
    int tc = 1;
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
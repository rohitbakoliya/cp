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
const int N = 2e6 + 5;
const long long INF = 1e18 + 37;

#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif

int timer;
vector<int> in, out, par, depth;
vector<vector<int> > v;
void dfs(int i = 0 , int parent = -1 , int d = 0){
    par[i] = parent;
    depth[i] = d;
    in[i] = timer++;
    for(auto x: v[i]){
        if(x == parent) continue;
        dfs(x , i, d+1);
    }
    out[i] = timer++;
}
inline bool isAnc(int a, int b){
    return in[b]>=in[a] && out[b]<=out[a];
}
void solve(){
    int n, m;
    cin >> n >> m;
    v.resize(n);
    in.resize(n);
    out.resize(n);
    par.resize(n);
    depth.resize(n);
    for(int i=0 ; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        a-- , b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs();
    while(m--){
        int k;
        cin >> k;
        vector<int> nodes(k);
        for(auto &x: nodes){
            cin >> x;
            x--;
        }
        int u = nodes.front();
        for(int i=1; i<k; i++){
            if(depth[nodes[i]] > depth[u]) u = nodes[i];
        }
        for(auto &x: nodes){
            if(x == u || par[x]==-1) continue;
            x = par[x];
        }
        bool ok = true;
        for(auto x: nodes){
            if(!isAnc(x,u)){
                ok = 0;
            }
        }

        cout <<(ok ? "YES" : "NO") << endl;
    }

}

signed main() {
    FAST
    int tc = 1;
    //TODO : check for tc
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}

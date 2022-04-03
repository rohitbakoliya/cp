#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Int int32_t
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define bitcnt(n) __builtin_popcountll(n)
#define setpre(n) cout << fixed << setprecision(n)
#define tr(c) for(const auto& x : c )cout << x << " "; cout << "\n";
#define ol(c, s, e) for(int pos=s; pos<e; pos++)cout << c[pos] << " ";cout <<"\n";
#define PI acos(-1LL)


//----------------https://www.youtube.com/watch?v=Xng1Od_v6Ug&list=PLfBJlB6T2eOsET4tlfcLs7oXR7kCyt1xc&index=2

const int M = 1000000007;
const int N = 2e5 + 5;
const long long INF = 1e9 + 12;

//---------COPY FROM HERE-----------------------------------------
vector<vector<int>> v;
vector<int> in, out, dp;

void dfs1(int i, int par){
    for(int x: v[i]){
        if(x == par) continue;
        dfs1(x,i);
        in[i] = max(in[i], in[x]+1);
    }
}


void dfs2(int i, int par){
    int mx1 = -1, mx2 = -1;
    //find top 2 maximum values of in[v]
    for(int x: v[i]){
        if(x == par) continue;
        if(in[x] >= mx1) mx2 = mx1 , mx1 = in[x];
        else if(in[x] >mx2) mx2 = in[x];
    }
    for(int x: v[i]){
        if(x == par) continue;
        int use = mx1;
        if(use == in[x])
            use = mx2;
        out[x] = max(1+out[i], 2 + use);
        dfs2(x,i);
    }
}

//---------COPY TILL HERE-----------------------------------------

void solve(){
    int n;
    cin >> n;
    v.resize(n+1);
    in.resize(n+1,0);
    out.resize(n+1,0);
    dp.resize(n+1);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1; i<=n; i++){
        dp[i] = max(in[i], out[i]);
//        cout << in[i] << " " << out[i] << " " << dp[i] << " " << endl;
        cout << dp[i] << " ";
    }
}
/*
10
1 2
1 3
1 4
2 5
2 6
3 7
4 8
7 9
7 10
3 4 3 4 5 5 4 5 5 5
 */
signed main(){
    FAST
    int tc = 1;
//    TODO: check for tc
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}

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


#ifdef LOCAL
string to_string(const string& s){
    return '"' + s + '"';
}
string to_string(const char* s) {
    return to_string((string) s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename T>
string to_string(T v){
    bool first = true;
    string res = "{";
    for(const auto& x: v){
        if(!first) res+=", ";
        first = false;
        res+=to_string(x);
    }
    res+="}";
    return res;
}
void bug() { cerr << endl; }
template<typename Head, typename... Tail>
void bug(Head H, Tail... T) {
    cerr << " " << to_string(H);
    bug(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__);
#endif


const int M = 1000000007;
const int N = 2e6 + 5;
const long long INF = 2e18 + 12;

// -------------COPY FROM HERE------------
#warning invoke resizes after reading n
int n, mxN;
vector<vector<int>> v, LCA;
vector<int> level;
void dfs(int i, int d = 0,  int par = -1){
    LCA[i][0] = par;
    level[i] = d;
    for(int x: v[i]){
        if(x == par) continue;
        dfs(x, d+1 , i);
    }
}
void resizes(){
    v.resize(n+1);
    level.resize(n+1, 0);
    mxN = log2(n);
    LCA.resize(n+1, vector<int>(mxN+1, -1));
}
void init(){
    #warning check root as well
    int root = 1;
    dfs(root);
    for(int j=1; j<=mxN; j++){
        for(int i=1; i<=n; i++){
            int par = LCA[i][j-1];
            if(par == -1) continue;
            LCA[i][j] = LCA[par][j-1];
        }
    }
}
int findLCA(int a, int b){
    if(level[a] < level[b]){
        swap(a,b);
    }
    int diff = level[a] - level[b];
    while(diff>0) {
        int i = log2(diff);
        a = LCA[a][i];
        diff-=(1LL<<i);
    }
    if(a == b) return a;

    //now both nodes at same level
    for(int i=mxN; i>=0; i--){
        if(LCA[a][i]!=-1 && LCA[a][i]!=LCA[b][i])
            a = LCA[a][i], b = LCA[b][i];
    }
    return LCA[a][0];
}

int findDis(int a, int b){
    int lca = findLCA(a, b);
    return level[a] + level[b] - 2*level[lca];
}

//-------COPY TILL HERE-------------

void solve(){
    cin >> n;
    resizes();
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        v[a].pb(b), v[b].pb(a);
    }
    init();
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << findDis(a,b) << endl;
    }
}

signed main(){
    FAST
#ifdef LOCAL
    clock_t start;
    double duration;
    start = clock();
#endif
    int tc = 1;
//    TODO: check for tc
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
//        cout << "Case #" << t << ": ";
        solve();
    }
#ifdef LOCAL
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cerr <<"\nTotal time elapsed: "<< duration <<"sec\n";
#endif
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
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
#else
#define debug(...) 11;
#endif


const int M = 1000000007;
const int N = 2e6 + 5;
const long long INF = 2e17 + 12;


vector<int> v[100001];
vector<int> in, out, ft;
int n, timer = 1;
//flat tree
void dfs(int i, int par){
    in[i] = timer;
    ft[timer] = i;
    timer++;
    for(auto x: v[i]){
        if(x == par) continue;
        dfs(x, i);
    }
    out[i] = timer;
    ft[timer] = i;
    timer++;
}

void solve(){
    cin >> n;
    in.resize(n+1);
    out.resize(n+1);
    ft.resize(2*n+1);
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1, -1);
    debug(in, out, ft);
}
signed main(){
    FAST
#ifdef TIMER
    clock_t start;
    double duration;
    start = clock();
#endif
    int tc = 1;
//    TODO: check for tc
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
#ifdef TIMER
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cerr <<"\n\nTotal time elapsed: "<< duration <<"sec\n";
#endif
}

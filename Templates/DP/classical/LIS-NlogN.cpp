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
const int N = 6e5 + 5;
const long long INF = 1e18 + 37;

#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif

void solve(){
    int n;
    cin >> n;
    vector<int > v;
    for(int i=0 ; i<n; i++){
        int a;
        cin >> a;
        int ub = upper_bound(all(v) , a) - v.begin();
        if(ub < v.size()){
            v[ub] = a;
        } else{
            v.pb(a);
        }
    }
//    tr(v);
    cout << v.size();

}

signed main() {
    FAST
    int tc = 1;
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
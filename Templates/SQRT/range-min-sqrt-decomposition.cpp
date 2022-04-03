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
#define ol(c , s , e ) for(int pos=s; pos<e ; pos++) cout << c[pos] << " ";
#define PI acos(-1l)
const int M = 1000000007;
const int N=1e5+5;
const int INF = 2e18+5;
//#define rohit
#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif

const int BLK = 500;
int a[N] , block[BLK+1];
void init(){
    for(int i=0 ; i<=BLK; i++)
        block[i] = INF;
    for(int i=0; i<N ; i++){
        block[i/BLK] = min(block[i/BLK] , a[i]);
    }
}
void update(int ind , int value){
    block[ind/BLK] = min(block[ind/BLK], value);
    a[ind] = value;
}
int query(int l , int r ){
    int mn = INF;
    int LB = l/BLK;
    int RB = r/BLK;
    if(LB == RB){
        for(int i = l; i<=r ; i++)
            mn = min(mn , a[i]);
    }
    else{
        for(int i=l; i<(LB+1)*BLK; i++){
            mn = min(mn , a[i]);
        }
        for(int i = LB+1 ; i<RB ; i++)
            mn = min(mn , block[i]);
        for(int i=BLK*RB; i<=r ; i++)
            mn = min(mn , a[i]);
    }
    return mn;
}
void solve(){
    int n;
    cin >> n;
    for(int i=0 ;i <n ; i++){
        cin >> a[i];
    }
    init();
    int q;
    cin >> q;
    while(q--){
        int l , r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }
}

signed main(){
    FAST;
    //TODO: check test cases.
    int tc=1;
//    cin >> tc;
    for(int t = 1 ; t <= tc ; t++){
        solve();
    }
}
/* Extra Cares
 * 1)In graphs or dp problems sometimes long long creates MLE.
 * 2)Check whether int to long long typecasting is commented or not?
 * 3)Check overflows.
*/


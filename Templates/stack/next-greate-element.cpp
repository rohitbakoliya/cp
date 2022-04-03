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
const int N=3e3+5;
const long long INF = 1e9+5;
//#define rohit
#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif
const int MOD = 2019;
void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++ ) cin >> a[i];
    stack< int > stk;
    stk.push(a[0]);
    for(int i=1 ; i<n ; i++){
        while(!stk.empty() && stk.top() < a[i]){
            cout << stk.top() << " --> " << a[i] << endl;
            stk.pop();
        }
        stk.push(a[i]);
    }
    while(!stk.empty()){
        cout << stk.top() << " --> -1\n";
        stk.pop();
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


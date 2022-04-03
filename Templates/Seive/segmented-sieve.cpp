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
const int N=3e5+5;
const long long INF = 1e9+5;
//#define rohit
#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif


// IDEA
// generate all the primes using simple sieve till sqrt(R) and cancle all the multiples in range[L , R].


// -------------------------- COPY FROM HERE --------------------
vector< int > primes;

//TODO: initialize in main
void sieve(){
    vector< bool > prime(N, true);
    //N should be sqrt(R) in worst case;
    //here i<=N because N is already taken as sqrt(R)
    for(int i=2 ; i<=N ;i++){
        if(prime[i]){
            primes.pb(i);
            for(int j=i*i ; j<=N ; j+=i){
                prime[j] = false;
            }
        }
    }
}

//segmented - sieve function 
void init(int l , int r){
    if(l == 1 ) l++;
    int range = r - l + 1;
    vector< bool > prime(range , true);
    for(auto p : primes){
        if(p*p <= r ){
            int i = (l/p)*p;
            if(i < l ) i+=p;
            for( ; i<=r ; i+=p){
                if(i!=p){
                    prime[i-l] = false;
                }
            }
        }
    }
    for(int i=0 ; i<range ; i++){
        if(prime[i]){
            cout << l+i << endl;
        }
    }
}
void solve(){
    int l , r;
    cin >> l >> r;
    init(l , r);
    cout << endl;
}

signed main(){
    FAST;
    //TODO: check test cases.
    int tc=1;
    sieve();
    cin >> tc;
    for(int t = 1 ; t <= tc ; t++){
        solve();
    }
}
/* Extra Cares
 * 1)In graphs or dp problems sometimes long long creates MLE.
 * 2)Check whether int to long long typecasting is commented or not?
 * 3)Check overflows.
*/


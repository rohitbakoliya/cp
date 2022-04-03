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


//totient funtction counts the no. of positive integer less than n that are coprime to n; 
//Refer this: https://www.youtube.com/watch?v=jtmi7Fj7fgE&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=25

//----------------------------------------------------COPY FROM HERE------------------

//O(sqrt(N))
int totient(int n){
    int res =  n;
    for(int i=2 ; i*i<=n ; i++){
        if(n%i==0){
            res/=i;
            res*=(i-1);
            while(n%i==0)
                n/=i;
        }
    }
    if(n > 1 ){
        res/=n;
        res*=(n-1);
    }
    return res;
}

//O(N*Log(logN)) N < 1e6;
//TODO: initialize in main

int phi[N+1];
void init(){
    for(int i=1; i<=N ;i++){
        phi[i] = i;
    }
    for(int i=2 ; i<=N ; i++){
        if(phi[i] == i){
            for(int j=i ; j<=N ; j+=i){
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}
//----------------------------------------------------COPY TILL HERE------------------

void solve(){
    int n;
    cin >> n;
    cout << totient(n) << endl;
    cout << phi[n] << endl;
}

signed main(){
    FAST;
    //TODO: check test cases.
    int tc=1;
    cin >> tc;
    init();
    for(int t = 1 ; t <= tc ; t++){
        solve();
    }
}
/* Extra Cares
 * 1)In graphs or dp problems sometimes long long creates MLE.
 * 2)Check whether int to long long typecasting is commented or not?
 * 3)Check overflows.
*/


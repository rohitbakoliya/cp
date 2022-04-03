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
const int N=2e5+5;
const int INF = 2e18+5;
//#define rohit
#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif
//-----------------COUNT UNIQUE ELMENTS IN OFFLINE QUERIES ---------------
//O((N+Q)*SQRT(N))

struct Query{
    int l;
    int r;
    int ind;
};
Query Q[N];
const int BLK = 600;
int a[N], freq[1000005], ans[N];
int cnt = 0;
bool comp(Query x, Query y ){
    if(x.l/BLK !=y.l/BLK)
        return x.l/BLK < y.l/BLK;
    return x.r < y.r ;
}

void add(int pos){
    freq[a[pos]]++;
    if(freq[a[pos]]==1)
        cnt++;
}
void remove(int pos){
    freq[a[pos]]--;
    if(freq[a[pos]]==0)
        cnt--;
}
void solve(){
    int n;
    cin >> n;
    for(int i=0 ;i <n ; i++){
        cin >> a[i];
    }
    int q;
    cin >> q;
    for(int i=0 ; i< q ; i++){
        Q[i].ind = i;
        int l , r;
        cin >> l >> r;
        l-- , r--;
        Q[i].l = l , Q[i].r = r;
    }
    sort(Q , Q+q , comp);
    int curL = 0, curR = -1;

    for(int i=0; i<q ; i++){
        int L = Q[i].l;
        int R = Q[i].r;
        while(curL > L)
            add(--curL);
        while(curR < R)
            add(++curR);
        while(curL < L)
            remove(curL++);
        while(curR > R)
            remove(curR--);
        ans[Q[i].ind] = cnt;
    }
    for(int i=0 ; i<q ;i++){
        cout << ans[i] << endl;
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


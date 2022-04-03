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
int seg[N<<2];
void build(int *a , int l , int r , int node ){
    if(l == r ){
        seg[node] = a[l];
        return;
    }
    int mid = l + (r - l )/2;
    build(a , l , mid , 2*node);
    build(a , mid+1 , r , 2*node+1);
    seg[node] = min(seg[2*node] , seg[2*node + 1]);
}

int query(int l , int r , int ql , int qr , int node){
    if(l > qr ||  r < ql)
        return INF;
    if(l>=ql && r<=qr)
        return seg[node];
    int mid = l + (r - l )/2;
    int L = query(l , mid , ql , qr , 2*node);
    int R = query(mid+1 , r , ql , qr , 2*node+1);
    return min(L , R);
}

//for point update
//and also update a[ind] = value in called function
void update(int *a , int l , int r , int ind , int val, int node ){

    if(l == r ){
        a[ind] = val;
        seg[node] = val;
        return;
    }
    int mid = l + (r - l )/2;
    if(ind <= mid )
        update(a , l , mid , ind , val , 2*node );
    else
        update(a , mid+1, r , ind , val, 2*node+1);
    seg[node] = min(seg[2*node] , val, seg[2*node+1]);
}
void solve(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i=1; i<=n ;i++){
        cin >> a[i];
    }
    memset(seg , INF , sizeof(seg));
    build(a , 1 , n , 1);
    int q;
    cin>> q;
    while(q--){
        int l , r;
        cin >> l >> r;
        l++ , r++;
        cout << query(1 ,n , l , r , 1) << endl;
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












































//-------------------------OLD implementation
/*#include<bits/stdc++.h>
using namespace std;
int st[1000001];
void fill(){
    for(int i=0 ; i<=1000000 ; i++)
    st[i] = INT_MAX;
    
}
void build(int* a , int start , int end , int node)
{
    if(start==end){
        st[node]=a[start];
        
        return;
    }
    else{
        int mid = (start + end)/ 2;
        build(a , start , mid , 2*node + 1);
        build(a , mid+1 , end , 2*node + 2);
        st[node]=min(st[2*node+1] , st[2*node+2]);
    }
}
void update(int *a , int start , int end , int node , int ind , int val)
{
    if(start==end){
        a[ind] = val;
        st[node] = val;
        return;
    }
    else
    {
        int mid = (start + end)/2;
        if(start<=ind && ind<=mid){
            update(a , start , mid , 2*node + 1 , ind , val);
        }
        else{
            update(a , mid + 1 , end , 2*node + 2 , ind , val);
        }
        st[node] = std::min(st[2*node + 1],st[2*node + 2]);
    }
}
int query(int *a , int start , int end , int l , int r , int node)
{
    if(r<start || end<l)return INT_MAX;
    if(l<=start && r>=end) return st[node];

    int mid = (start + end)/2;
    int p1 = query(a , start , mid , l , r , 2*node + 1);
    int p2 = query(a , mid+1 , end , l , r , 2*node + 2);
    int mn = min(p1 ,p2);
    return mn;
}
int main()
{
    int n , q, i;
    cin>>n>>q;
    fill();
    int *a = new int[n];
    for(i=0 ;i<n ; i++){
      cin>>a[i];
    } 
    build(a , 0 , n-1 , 0);
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='q')
        {
            int l , r;
            cin>>l>>r;
            l--, r--;
            cout<<query(a , 0 , n-1 , l , r , 0 )<<"\n";
        }
        else{
            int ind , val;
            cin>>ind>>val;
            ind--;
            update(a , 0 , n-1 , 0 , ind , val);
        }
    }
}*/
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
const int N=1e3+5;
const int INF = 2e18+5;
//#define rohit
#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif
int a[N], seg[N<<2], lazy[N<<2];
void build(int l , int r , int node){
    if(l == r){
        seg[node] = a[l];
        return;
    }
    int mid = l + (r - l)/2;
    build(l , mid , 2*node);
    build(mid+1, r, 2*node+1);
    seg[node] = seg[2*node] + seg[2*node+1];
}

int query(int l ,int r , int node , int ql , int qr){
    if(lazy[node]!=0){
        int dx = lazy[node];
        lazy[node] = 0;
        seg[node]+=dx*(r - l + 1);
        if(l!=r){
            lazy[2*node] +=dx;
            lazy[2*node+1] +=dx;
        }
    }
    if(l > qr || r < ql) return 0;
    if(l>=ql && r<=qr ) return seg[node];

    int mid = l + (r-l)/2;
    return query(l, mid , 2*node , ql , qr) + query(mid+1, r, 2*node+1 , ql , qr);
}

void update(int l, int r ,int node , int ql , int qr , int val){
    if(lazy[node]!=0){
        int dx = lazy[node];
        lazy[node] = 0;
        seg[node]+=dx*(r - l + 1);
        if(l!=r){
            lazy[2*node] +=dx;
            lazy[2*node+1] +=dx;
        }
    }
    if(ql > r || qr < l) return;
    if(l>=ql && r<=qr ){
        int dx = (r - l+1)*val;
        seg[node]+=dx;
        if(l!=r){
            lazy[2*node] +=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    int mid = l + (r-l)/2;
    update(l , mid , 2*node , ql , qr , val);
    update(mid+1 , r , 2*node+1 , ql , qr , val);
    seg[node] = seg[2*node] + seg[2*node+1];
}
void solve(){
    int n , q , code , l , r , val;
    cin>>n>>q;
    build( 1 , n,1 );

    while(q--)
    {
        cin>>code;
        if(code == 1)
        {
            cin>>l>>r;
            cout<<query( 1 , n, 1, l , r)<<endl;
        }
        else
        {
            cin>>l>>r>>val;
            update(1 , n , 1 , l , r , val);
        }
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


































































//-------------------------------------------OLD IMPLEMENTATION

/*
#include <bits/stdc++.h>
using namespace std;
int st[20]={0};
int lazy[20]={0};

1) If current segment tree node has any pending
update, then first add that pending update to
        current node.
2) If current node's range lies completely in
update query range.
....a) Update current node
....b) Postpone updates to children by setting
lazy value for children nodes.
3) If current node's range overlaps with update
range, follow the same approach as above simple
        update.
...a) Recur for left and right children.
...b) Update current node using results of left
and right calls*/
/*
void build(int *a , int start , int end , int node)
{
    if(start == end)
    {
        st[node] = a[start];
        return;
    } else{
        int mid = (start + end)/2;
        build(a , start , mid , 2*node + 1);
        build(a , mid +1 , end , 2*node + 2);
        st[node] = st[2*node + 1 ] + st[2*node + 2];
    }
}
void update(int *a , int start , int end , int l , int r ,int node , int val )
{
    if(lazy[node]!=0)
    {
        st[node]+=(end - start + 1 ) * lazy[node];
        if(start!=end)//that is for non leaf nodes
        {
            lazy[2*node +1 ]+=lazy[node];
            lazy[2*node +2 ]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start > end  || start > r || end < l)
        return;
    if(l<=start && r>=end)
    {
        st[node]+=val;
        if(start!=end)//then propagate the value to the children's;
        {
            // Not leaf node
            lazy[2*node + 1]+=val;
            lazy[2*node + 2]+=val;
        }
        return;
    }
    int mid = (start + end)/2;
    update(a , start , mid , l , r,2*node + 1 , val);
    update(a , mid+1 , end , l , r,2*node + 2 , val);
    st[node] = st[2*node + 1] + st[2*node + 2];
}
int query(int *a , int start , int end , int l , int r , int node)
{
    if(lazy[node]!=0)
    {
        st[node] +=lazy[node];
        if(start!=end)
        {
            lazy[2*node + 1]+=lazy[node];
            lazy[2*node + 2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start > end || r< start || l>end)
        return 0;
    if(start>=l && end<=r)
    {
        return st[node];
    }
    int mid = (start + end)/2;
    int p1 = query(a , start , mid , l , r , 2*node + 1);
    int p2 = query(a , mid + 1 , end , l , r , 2*node + 2);
    return (p1 + p2);
}
int main()
{
    int a[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(a)/sizeof(a[0]);

    // Build segment tree from given array
    build(a , 0 , n-1 , 0);
    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n",
           query(a , 0 , n-1 , 1, 3 , 0));

    // Add 10 to all nodes at indexes from 1 to 5.
    update(a , 0 , n-1, 1, 5, 0 , 10);
    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n",
           query(a , 0 , n-1 , 1, 3 , 0));

    return 0;
}
*/
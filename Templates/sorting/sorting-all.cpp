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
const long long INF = 1e15+5;
//#define rohit
#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif

void selectionSort(){
    vector< int > v{3,1,9,6,8,7,2,5};
    int n = v.size();
    for(int i=0 ; i<n ;i++){
        int mn = 10 , mni = i;
        for(int j=i+1 ; j<n ; j++){
            if(mn > v[j]){
                mni = j;
                mn = v[j];
            }
        }
        if(mn < v[i]){
            v[mni] = v[i];
            v[i] = mn;
        }
    }
    tr(v);
}
void insertionSort(){
    vector< int > a{3,1,9,6,8,7,2,5};
    int n = a.size();
    for(int i=1 ; i<n ; i++){
        int temp = a[i] , j = i-1;
        while(j>=0 && a[j] > temp){
                a[j+1] = a[j];
                j--;
        }
        j++;
        a[j] = temp;
    }
    tr(a);
}
void bubbleSort(){
    vector< int > a{3,1,9,6,8,7,2,5};
    int n = a.size();
    for(int i=0 ; i<n ;i++){
        for(int j=0 ;j<n-i-1; j++){
            if(a[j] > a[j+1]){
                swap(a[j] , a[j+1]);
            }
        }
    }
    tr(a);
}
void solve(){
    
}
signed main(){
    FAST;
    //TODO:  check test cases.
    int tc=1;
//    cin >> tc;
    for(int t = 1 ; t <= tc ; t++){
        solve();
    }
}


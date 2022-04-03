#include<bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define int long long
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pii pair< int , int >
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define bitcnt(n) __builtin_popcountll(n)
#define tr(c) for(auto x : c )cout << x << " ";
#define ol(c , s , e ) for(int pos=s; pos<e ; pos++) cout << c[pos] << " ";
#define PI acos(-1)
const int M = 1000000007;
const int N=1e6 + 3;
int dp[51][N];
signed main()
{
    FAST;
    int n , c;
    cin >> n >> c;
    int w[n] , v[n];
    for(int i =0 ; i<n ;i++){
        cin >> v[i];
    }
    for(int i = 0 ; i<n ;i++){
        cin >> w[i];
    }
    
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=c ; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
                continue;
            }
            if(j < w[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , v[i-1] + dp[i-1][j - w[i-1]]);
            }
        }
    }
    cout << dp[n][c] << endl;
}

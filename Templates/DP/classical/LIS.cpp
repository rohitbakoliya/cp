#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
#define sz(a) int((a).size())
#define F first
#define S second
const int M = 1000000007;
const int N=3e5+5;

int32_t main()
{
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector< int > a(n+1) , dp(n+1);
        for(int i=1 ; i<=n ; i++) {
            cin >> a[i];
        }
        int mx = -1;
        for(int i=1 ; i<=n ; i++){
            //BASE CASE=> min one lenght subsequence
            dp[i] = 1;
            for(int j=1 ; j<i; j++){
                if(a[j] < a[i]){
                    dp[i] = max(dp[i] , dp[j] + 1);
                }
            }
            mx = max(mx , dp[i]);
        }
        cout << mx << endl;
        
    }
}
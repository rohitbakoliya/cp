#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
#define F first
#define S second
#define PI acos(-1)
const int M = 1000000007;
const int N=3e5+5;


int32_t main()
{
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        string a , b;
        a.push_back('#');
        b.push_back('#');
        
        for(int i = 1; i<=n ; i++){
            char c;
            cin >> c;
            a+=c;
        }
        for(int i=1 ; i<=m ;i++){
            char c;
            cin >> c;
            b+=c;
        }
        int dp[n+1][m+1];
        for(int i=0 ; i<=n ; i++) dp[i][0] = 0;
        for(int i=0 ; i<=m ; i++) dp[0][i] = 0;
        
        for(int i=1 ; i<=n ;i++){
            for(int j=1; j<=m ; j++){
                if(a[i]==b[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        cout << dp[n][m] << endl;
        
    }
}
// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
// https://youtu.be/KVfxgpI3Tv0
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
#define F first
#define S second
const int M = 1000000007;
const int N=3e5+5;
int32_t main()
{
    int tc;
    cin >> tc;
    while(tc--) {
        int n, k;
        cin >> n >> k;
        int dp[n+1][k+1];
        //store minimum no of attempts at i,j
        for(int i=0 ; i<=k ; i++){
            dp[0][i] = 0;
            dp[1][i] = i;
        }
        for(int i=0 ; i<=n ; i++){
            dp[i][0] = 0;
        }
        //If an egg breaks when dropped, then it would break if dropped from a higher floor.
        //.If an egg survives a fall then it would survive a shorter fall
        for(int i=2 ; i<=n; i++){
            for(int j=1 ; j<=k ; j++){
                dp[i][j] = INT_MAX;
                for(int z=1; z<=j; z++){
                    dp[i][j] = min(dp[i][j] ,1+max(dp[i-1][z-1]/*egg breaks*/ , dp[i][j-z]));
                }
            }
        }
        cout << dp[n][k] << endl;
    }
    
}
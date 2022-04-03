#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    string s;
    cin >> s;
    s.insert(s.begin(), '#');
    n = s.size();
    //dp[i][j] length i substring ends at j;
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int j=0; j<=n; j++){
        dp[0][j] = 1;
        dp[1][j] = 1;
    }
    int mxLen = 1, mxEnd = 1;
    for(int i=2; i<=n; i++){
        int len = 0 , end = -1;
        for(int j=i; j<=n; j++){
            if(s[j] == s[j-i+1]){
                dp[i][j] = dp[i-2][j-1];
            }
            else{
                dp[i][j] = 0;
            }
            if(end == -1 && dp[i][j]){
                len = i;
                end = j;
            }
        }
        if(end!=-1){
            mxLen = len;
            mxEnd = end;
        }
    }
    for(int i = mxEnd-mxLen+1; i<= mxEnd; i++){
        cout << s[i];
    }
    cout << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}
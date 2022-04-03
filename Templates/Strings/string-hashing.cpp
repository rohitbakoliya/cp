#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+7;
const int M = 1e9+7;
//we mutliply every hast with p_pow[n-l-1] becasue we want to make same string's hash same.
//for eg. ......[...S(i)...]....[....S(j)....] where S(i) and S(j) are **same** substrings 
//where i and j denotes starting position of substring. 
//the hash[S[i]] = p_pow[i]*(actual_hash_value) and
//similary  hash[s[j]] = p_pow[j] *(actual_hash_value)
//since both the strings are same than those hash also should be same.
//but they didn't same.
//to make to make both the hashes same we multiply each hash with some p_pow such that it makes constant cooefficient
//so we multiply with p_pow[n-i-1] and p_pow[n-j-1] respectively.
// then hash[s[i]] = p_pow[i]*p_pow[n-i-1] => pow[n-1]
//which is constant so for now hash[s[i]] = p_pow[n-1]*(actual_hash_value); 



//copy from here

const int p = 31; // or 53 for uppercase and lower case;
int h[N];
int p_pow[N];

void compute_hash(string const& s) {
    int n = s.length();
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i - 1] * p) % M;
    h[0] = 0;
    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % M;
}


int getHash(int l , int r , int n){
    int cur_h = (h[r+1] + M - h[l]) % M;
    cur_h =( cur_h* p_pow[n-l-1])%M;
    return cur_h;
}

//till now
void solve(){
   string s;
    cin >> s;
    compute_hash(s);
    int n = s.length() , cnt =0 ;
    for(int i=2 ; i<n ; i+=2){
        int t1 = getHash(0 , i/2-1 ,n);
        int t2 = getHash(i/2 , i-1 , n);
        int t3 = getHash(i , (i+n)/2 - 1 ,n);
        int t4 = getHash((i+n)/2 , n-1 , n);
        if(t1 == t2 && t3 == t4){
            cnt++;
        }
    }
    cout << cnt << endl;
}
signed main(){
    int tc=1;
    cin >> tc;
    for(int t = 1 ; t <= tc ; t++)
    {
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define int long long
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
#define F first
#define S second
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

const int M = 1000000007;
const int N=3e5+5;

int KMP(string& text, string& pattern)
{
     int cnt=0;

     int index = 0;
     int lps[pattern.length()];
     lps[0] = 0;
     /*
     * computing lps
     */
     for(int i=1; i < pattern.length() ;){
          if(pattern[i] == pattern[index]){
               lps[i] = index + 1;
               index++;
               i++;
          }else{
               if(index != 0){
               index = lps[index-1];
               }else{
               lps[i] =0;
               i++;
               }
          }
     }

     /*
     * KMP search   
     */
     int i=0;
     int j=0;
     while(i < text.length()){
          if(text[i] == pattern[j]){
               i++;
               j++;
          }
          if (j == pattern.length()) { 
               //cout << "Found pattern at " <<  i - j << endl; 
               j = lps[j - 1]; 
               cnt++;
          } 
          else if (i < text.length() && pattern[j] != text[i]) { 
               if (j != 0) 
                    j = lps[j - 1]; 
               else
                    i++;
          }
     }
     return cnt;

}



signed main()
{
    string p , t;
    cin >> p >> t;
    cout <<  KMP(t , p) << endl;
}


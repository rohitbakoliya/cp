#include<bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define int long long
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define bitcnt(n) __builtin_popcountll(n)
#define tr(container , s ) for(auto x : container ){cout << x << s;} cout<<endl;
#define one(x) cerr<<#x<<" : "<<x<<endl;
#define two(x,y) cerr<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<endl;
#define three(x,y,z) cerr<<#x<<" : "<<x<<" , "<<#y<<" : "<<y<<" , "<<#z<<" : "<<z<<endl;
#define PI acos(-1)
const int M = 1000000007;
const int N=1e5+5;
//*** basic

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool prime[N+1];
void sieve()
{
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    prime[0] = false;
    for (int p=2; p*p<=N; p++)
    {
        if (prime[p])
        {
            for (int i=p*p; i<=N; i += p)
                prime[i] = false;
        }
    }
}
signed main()
{
    int x ;
    cin >>x;
    sieve();
}


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1000000007;


long long bexp(int x , int n )
{
    long long result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=result * x;
        x=x*x;
        n=n/2;
    }
    return result;
}
int powmod(int x,int n , int mod = M)
{
    int result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result%mod* x%mod)%mod;
        x=(x%mod*x%mod)%mod;
        n=n/2;
    }
    return result;
}

// handles 10^12 * 10^12
int product_mod(int a, int b, int mod) {
    a %=mod;
    int res = 0;
    while(b)
    {
        if(b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

/**Fermat's Little Theorem**/
//If M is prime 
int modInverse(int A)
{
    return powmod(A,M-2);
}

signed main()
{
    cout << powmod(1212 , 50000) << endl;
    cout << modInverse(2) << endl;
    cout << (1212%M*10000023002%M)%M << endl;
     cout << powmod(2 , 10) << " " << powmod(2 , 10) << endl;
}
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

int fact[N], invfact[N];

int pow(int a, int b, int m)
{
     int ans = 1;
     while (b)
     {
          if (b & 1)
               ans = (ans * a) % m;
          b /= 2;
          a = (a * a) % m;
     }
     return ans;
}
int modinv(int k)
{
     return pow(k, M - 2, M);
}

void precompute()
{
     fact[0] = fact[1] = 1;
     for (int i = 2; i < N; i++)
     {
          fact[i] = fact[i - 1] * i;
          fact[i] %= M;
     }
     invfact[N - 1] = modinv(fact[N - 1]);
     for (int i = N - 2; i >= 0; i--)
     {
          invfact[i] = invfact[i + 1] * (i + 1);
          invfact[i] %= M;
     }
}

int nCr(int x, int y)
{
     if (y > x)
          return 0;
     int num = fact[x];
     num *= invfact[y];
     num %= M;
     num *= invfact[x - y];
     num %= M;
     return num;
}

signed main()
{
     precompute();
     
}
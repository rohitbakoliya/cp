#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

//**** IT IS IN O(nlog(n))
int minPrime[N + 1];
void leastPrimeFactor()
{
     for (int i = 2; i * i <= N; ++i)
     {
          if (minPrime[i] == 0)
          { //If i is prime
               for (int j = i * i; j <= N; j += i)
               {
                    if (minPrime[j] == 0)
                    {
                         minPrime[j] = i;
                    }
               }
          }
     }
     for (int i = 2; i <= N; ++i)
     {
          if (minPrime[i] == 0)
          {
               minPrime[i] = i;
          }
     }
}

//**** ALL PRIME FACTORS
//**** IT IS IN O(LOG N)
vector<int> getPrimeFactorization(int x)
{

     vector<int> res;
     while (x != 1)
     {
          res.push_back(minPrime[x]);
          x = x / minPrime[x];
     }
     return res;
}

//**** ALL FACTORS with repetitions
//**** IT IS IN O(sqrt(N))
vector<int> factorize(int n)
{
     vector<int> res;
     for (int i = 2; i * i <= n; ++i)
     {
          while (n % i == 0)
          {
               res.push_back(i);
               n /= i;
          }
     }
     if (n != 1)
     {
          res.push_back(n);
     }
     return res;
}

/*
5
3 2 4 2 6
ans : 6 
(1,5), (2,3), (2,4), (2,5), (3,4), (4,5) .
*/
void countOfAllPairsWithCommonFactors()
{
     int f[N+1];
     memset(f , 0 , sizeof(f));
     int ans = 0;
     for (int i = 1; i <= N; i++)
     {
          ans += (f[i] * (f[i] - 1)) / 2;
          for (int j = 2 * i; j <= N; j += i)
          {
               ans += f[i] * f[j];
          }
     }
}

int main()
{
}
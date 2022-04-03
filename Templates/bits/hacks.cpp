#include <bits/stdc++.h>
using namespace std;
///a+b = (a XOR b) + (a AND b)*2 
void possibleSubsets(char a[], int n)
{
     for (int i = 0; i < (1 << n); ++i)
     {
          for (int j = 0; j < n; ++j)
               if (i & (1 << j))
                    cout << a[j] << " ";
          cout << endl;
     }
}
bool check(int n , int i)
{
     if (n & (1LL << i))
          return true;
     else
          return false;
}
int count_one(int n)
{
     int count = 0;
     while (n)
     {
          n = n & (n - 1);
          count++;
     }
     return count;
}
bool isPowerOfTwo(int x)
{
     // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
     return (x && !(x & (x - 1)));
}
/***
 * 1) x ^ ( x & (x-1)) : Returns the rightmost 1 in binary representation of x.
 * 2) x & (-x) : Returns the rightmost 1 in binary representation of x
 * x | (1 << n) 
 * **/
int main()
{
}
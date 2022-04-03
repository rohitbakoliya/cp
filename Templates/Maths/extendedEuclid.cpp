#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1000000007;

/**Extended Euclidean algorithm**/
int d, x, y;
void extendedEuclid(int A, int B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

/**Modular multiplicative inverse**/
int modInverse(int A)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}


signed main()
{
    cout << modInverse(2) << endl;
    cout << (1212%M*10000023002%M)%M << endl;
}
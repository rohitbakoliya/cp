#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Int int32_t
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pii pair< int , int >
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define bitcnt(n) __builtin_popcountll(n)
#define setpre(n) cout << fixed << setprecision(n)
#define tr(c) for(auto x : c )cout << x << " ";
#define ol(c , s , e ) for(int pos=s; pos<e ; pos++) cout << c[pos] << " ";
#define PI acos(-1l)
const int M = 1000000007;
const int N=3e3+5;
const long long INF = 1e9+5;
//#define rohit
#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif


//Recurence relation
//        | A B |^(n-1) 
//[F1 F2]*| C D |       = [Fn F(n+1)] 

//O(LogN)
class MatrixExp{
public:
    int dim , n;
    static const int MaxDim = 51;
    int A[MaxDim][MaxDim] , I[MaxDim][MaxDim];
    void take_input(){
        for(int i=1 ; i<=dim ; i++){
            for(int j=1; j<=dim; j++){
                cin >> A[i][j];
            }
        }
    }
    void matrix_initilize(){
        A[1][1] = 0;
        A[1][2] = 1;
        A[2][1] = 1;
        A[2][2] = 1;
    }
    void make_identity(){
        for(int i=1 ; i<=dim ; i++){
            for(int j=1; j<=dim; j++){
                if(i==j)
                    I[i][j] = 1;
                else
                    I[i][j] = 0;
            }
        }
    }
    void matrix_multiplication(int X[][MaxDim] , int Y[][MaxDim]){
        int res[dim+1][dim+1];
        for(int i=1; i<=dim; i++){
            for(int j=1; j<=dim; j++){
                res[i][j] = 0;
                for(int k=1; k<=dim; k++){
                    res[i][j] = (res[i][j]%M +  X[i][k]*Y[k][j]%M)%M;
                }
            }
        }
        //coping result back to I
        for(int i=1; i<=dim; i++){
            for(int j=1; j<=dim; j++){
                X[i][j] = res[i][j];
            }
        }
    }
    void matrix_exp(){
        while(n){
            if(n%2==1) {
                matrix_multiplication(I, A);
                n--;
            }
            matrix_multiplication(A,A);
            n/=2;
        }
        //coping result back to A;
        for(int i=1 ; i<=dim; i++){
            for(int j=1; j<=dim ; j++){
                A[i][j] = I[i][j];
            }
        }
    }
    void matrix_print(){
        for(int i=1; i<=dim; i++){
            for(int j=1; j<=dim; j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};
void solve(){
    MatrixExp mat = MatrixExp();
    cin >> mat.dim >> mat.n;
    mat.take_input();
    mat.make_identity();
    mat.matrix_exp();
    mat.matrix_print();
}

signed main(){
    FAST;
    //TODO: check test cases.
    int tc=1;
    cin >> tc;
    for(int t = 1 ; t <= tc ; t++){
        solve();
    }
}
/* Extra Cares
 * 1)In graphs or dp problems sometimes long long creates MLE.
 * 2)Check whether int to long long typecasting is commented or not?
 * 3)Check overflows.
*/


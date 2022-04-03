#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define bitcnt(n) __builtin_popcountll(n)
#define setpre(n) cout << fixed << setprecision(n)
#define tr(c) for(const auto& x : c )cout << x << " "; cout << "\n";
#define PI acos(-1LL)

const int M = 1000000007;
const int N = 2e6 + 5;
const long long INF = 2e17 + 12;

//---------------COPY FROM HERE --------------


vector<int> v[100];
vector<int> in, res;
int n, m;
//TOPO SORT FOR DAG USING KAHN ALGORITHM
bool kahn(){
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i=1; i<=n; i++){
        if(in[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int cur = q.top();
        q.pop();
        res.pb(cur);
        for(int x: v[cur]){
            in[x]--;
            if(in[x] == 0){
                q.push(x);
            }
        }
    }
    return res.size() == n;
}


//-----------COPY TILL HERE

void solve(){
    cin >> n >> m;
    in.resize(n+1, 0);
    for(int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        in[b]++;
    }
    if(!kahn()){
        cout << "Contains Cycles.\n";
    }
    else{
        for(auto x: res){
            cout << x << " ";
        }
        cout << endl;
    }
}
signed main(){
    FAST
#ifdef TIMER
    clock_t start;
    double duration;
    start = clock();
#endif
    int tc = 1;
//    TODO: check for tc
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
#ifdef TIMER
    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    cerr <<"\n\nTotal time elapsed: "<< duration <<"sec\n";
#endif
}

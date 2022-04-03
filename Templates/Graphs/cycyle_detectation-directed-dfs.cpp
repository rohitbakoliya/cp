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


//----------COPY FROM HERE --------------------------
vector<vector<int>> v;
vector<int>color;
vector<int> parent;
int cycle_start, cycle_end, n;

bool dfs(int i){
    color[i] = 1;
    for(auto x: v[i]){
        if(color[x] == 0){
            parent[x] = i;
            if(dfs(x))
                return true;
        }
        else if(color[x] == 1){
            cycle_start = x;
            cycle_end = i;
            return true;
        }
    }
    color[i] = 2;
    return false;
}

void find_cycle(){
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;
    for(int i=0; i<n; i++){
        if(color[i] == 0 && dfs(i))
            break;
    }
    if(cycle_start == -1){
        cout << "Acyclic\n";
        return;
    }
    vector<int> cycle;
    cycle.pb(cycle_start);
    for(int node = cycle_end; node!=cycle_start; node = parent[node])
        cycle.pb(node);
    cycle.pb(cycle_start);
    reverse(all(cycle));
    cout << "Cycle Found: \n";
    for(auto x: cycle) cout << x << " ";
    cout << endl;

}


//----------COPY TILL HERE --------------------------


void solve(){

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

#include<bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define int long long
#define all(c) c.begin(), c.end()
#define FAST ios_base::sync_with_stdio(false) , cin.tie(NULL);
#define pii pair< int , int >
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define bitcnt(n) __builtin_popcountll(n)
#define setpre(n) cout << fixed << setprecision(n)
#define tr(c) for(auto x : c )cout << x << " ";
#define ol(c , s , e ) for(int pos=s; pos<e ; pos++) cout << c[pos] << " ";
#define inf 2e18;
const int M = 1000000007;
const int N=1e6+5;

//#define local
#ifdef local
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif




int cnt[N];
vector< int > v[N];

void dfs(int s, int e) {
    cnt[s] = 1;
    for(auto it: v[s]) {
        if(it == e)
            continue;
        dfs(it, s);
        cnt[s] += cnt[it];
    }
}
signed main()
{
    int tc=1 , i ,j;
    int n;
//    cin >> tc;
    while(tc--)
    {
        int k ;
        cin >> n >> k;
        for(i=0 ; i<N ;i++)
        {
            cnt[i] = 0;
        }
        for(i=0 ; i<n-1 ;i++)
        {
            int x , y;
            cin >> x >> y;
            v[x].pb(y);
            v[y].pb(x);
        }
        dfs(1 , 0);
    }
}

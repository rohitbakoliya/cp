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
#define ol(c, s, e) for(int pos=s; pos<e ; pos++) cout << c[pos] << " ";
#define PI acos(-1l)
const int M = 1000000007;
const int N = 3e3 + 5;
const long long INF = 1e9 + 37;

#ifdef rohit
template<typename... T >
void bug(T... __VA_ARGS__) {
    ((cerr << __VA_ARGS__ << " ") , ...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", bug(__VA_ARGS__) , cerr << endl;
#endif
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0 , -1, 0};

//int dx[8]={-1 ,-1,-1, 1, 1 , 1 , 0, 0};
//int dy[8]={-1 , 1, 0,-1, 1 , 0 ,-1, 1};
bool vis[N][N];
int dis[N][N];
pii from[N][N];
int n, m;
char s[N][N];

bool isValid(int x , int y){
    return x>=0 && x<n && y>=0 && y<m;
}
void bfs(int i, int j){
    vis[i][j] = 1;
    queue<pii> q;
    q.push({i, j});
    dis[i][j] = 0;
    while(!q.empty()){
        pii p = q.front();
        q.pop();
        int x = p.F , y = p.S;
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(isValid(nx, ny) && s[nx][ny]!='#' && !vis[nx][ny]){
                q.push({nx, ny});
                from[nx][ny] = {x, y};
                vis[nx][ny] = 1;
                dis[nx][ny] = dis[x][y] + 1;
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=m; j++){
            vis[i][j] = false;
            dis[i][j] = -1;
        }
    }
    int x,y , stx , sty;
    for(int i=0 ;i<n; i++){
        for(int j=0 ; j<m ;j++){
            cin >> s[i][j];
            if(s[i][j]=='B'){
                x = i;
                y = j;
            }
            else if(s[i][j] == 'A'){
                stx = i;
                sty = j;
            }
        }
    }
    bfs(stx, sty);
    if(dis[x][y] == -1){
        cout <<"NO\n";
    }
    else{
        cout <<"YES\n";
        cout << dis[x][y] << endl;
        vector<pii> ans;
        ans.push_back({x, y});
        pii st = from[x][y];
        pii ed = {stx , sty};
        while(st!=ed)
        {
            ans.push_back(st);
            st = from[st.F][st.S];
        }
        ans.push_back(ed);
        reverse(ans.begin() , ans.end());
        string res;
        for(int i=1 ; i<ans.size(); i++){
            if(ans[i].F == ans[i-1].F){
                if(ans[i].S == ans[i-1].S + 1){
                    res+='R';
                }
                else{
                    res+='L';
                }
            }
            else if(ans[i].S == ans[i-1].S){
                if(ans[i].F == ans[i-1].F + 1){
                    res+='D';
                }
                else{
                    res+='U';
                }
            }
        }
        cout << res << endl;
    }
}

signed main() {
    FAST;
    int tc = 1;
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
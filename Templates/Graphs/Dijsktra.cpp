/*
dijksra's algorithm won't work for negetive weighted edges.
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 2;
const int INF = 1e18;


vector< pair< int ,int > > v[N];
multiset< pair< int , int > > s;
int dis[N];
multiset< pair< int , int > > s;
//predecessor 
int p[N];

void dijkstra(int start)
{
     dis[start] = 0;
     s.insert({0 , start});
     while(!s.empty())
     {
          pair<int,int> tp = *s.begin();
          s.erase(s.begin());
          int x = tp.second , wt = tp.first;
          if(vis[x]){
               continue;
          }
          vis[x] = true;
          for(auto i : v[x]){
               if(dis[x] + i.second < dis[i.first]){
                    dis[i.first] = dis[x] + i.second;
                    s.insert({dis[i.first] , i.first});
                    p[i.first] = x; //for path
               }
          }
     }
}
vector< int > restore_path(int s , int t){
     vector< int > path;

     for(int v = t ; v!=s ; v = p[v]){
          path.push_back(v);
     }
     path.push_back(s);
     reverse(path.begin(), path.end());
     return path;
}
int main()
{
     int n , m ;
     cin >> n >> m;

     for(int i=0 ; i<=N ; i++) {
          dis[i] = INF;
          vis[i] = false;
          p[i] = -1;
     }
     for(int i=0 ; i<m ; i++){
          int a, b , c;
          cin >> a >> b >> c;
          v[a].push_back({b , c});
     }
     int start = 1;
     dijkstra(start);
     
     for(int i=2 ; i<=n ;i++){
          cout << dis[i]<<" " ;
     }
}
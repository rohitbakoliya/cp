#include<bits/stdc++.h>
using namespace std;

///O(N^3)
/*
Floyd–Warshall's Algorithm is used to find the shortest paths between between all pairs of 
vertices in a graph, where each edge in the graph has a weight which is positive or negative. 
*/
const int INF = 1e18;
int main()
{
     int v[1001][1001];
     int dis[1001][1001];
     int n = 1000;
     for(int i=0; i<=n; i++){
          for(int j=0 ; j<=n ; j++){
               if(i == j ) {
                    v[i][j] = 0;
               }
               else{
                    v[i][j] = INF;
               }
          }
     }
     // m will be no. of edges;
     int m = 1000;
     for(int i=0 ; i<m ; i++){
          int a , b , wt;
          cin >> a >> b >> wt;
          v[a][b] = wt;
     }
     for(int k = 1; k <= n; k++){
          for(int i = 1; i <= n; i++){
               for(int j = 1; j <= n; j++){
                    dis[i][j] = min( dis[i][j], dis[i][k] + dis[k][j] );
               }
          }
     }

}
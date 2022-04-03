/*
A very important application of Bellman Ford is to check if there is a negative cycle in the graph,
We can check this by performing relaxation one more time if dis changes it means there is negative cycle
and also Bellman ford not work for negative cycle
*/

/*
Bellman ford also works for negetive weights but dijksra's algorithm won't work.
*/
//O(V*E) in general case
//in case of complete graph O(N^3) bcoz |V| = N-1 , |E| = N*(N-1)/2
#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 2;
const int INF = 1e18;
int main()
{
     int n ,m;
     cin >> n >> m;
     vector< int > v[N];
     int dis[N];
     for(int i = 0 ; i<N ; i++){
          dis[i] = INF;
     }

     for(int i=0 ; i<m ;i++){
          int a , b , wt;
          cin >> a >> b >> wt;
          v[i].push_back(a);
          v[i].push_back(b);
          v[i].push_back(wt);
              
     }
     //source vertex dis is 0.
     dis[1] = 0;
     for(int i=0 ; i<n-1 ;i++){
          int j=0;
          while(v[j].size()!=0) // or for(int j=0 ; j < m ; j++)
          {
               if(dis[v[i][0]]!=INF && dis[v[j][0]] + v[j][2] < dis[v[j][1]]){
                    dis[v[j][1]] = dis[v[j][0]] + v[j][2];
               }
               j++;
          }
     }
     bool neg = false;
     //for checking negetive edge
     for(int i=0 ; i<m ; i++){
          if(dis[v[i][0]]!=INF && dis[v[i][0]] + v[i][2] < dis[v[i][1]]){
               cout << "Graph contains negative weight cycle\n";
               neg = true;
               break;
          }
     }
     for(int i=2 ; i<=n ; i++) cout << dis[i] << " ";
}
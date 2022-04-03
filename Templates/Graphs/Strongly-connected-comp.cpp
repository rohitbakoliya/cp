#include<bits/stdc++.h>
using namespace std;
//take a look at cp-algorithms

//reverse of order is topological order 
vector<int> order, vis;
int n;
void dfs(int i, vector<int> g[]){
    vis[i] = 1;
    for(auto x: g[i]){
        if(!vis[x]){
            dfs(x, g);
        }
    }
    order.push_back(i);
}


int kosaraju(vector<int> v[])
{
    int scc = 0;
    vector<int> rg[n];
    for(int i=0; i<n; i++){
        for(auto x: v[i]){
            rg[x].push_back(i);
        }
    }
    
    order.clear();
    vis.assign(n, false);
    dfs(0, v);
    vis.assign(n, false);
    
    for(int i=0; i<n; i++){
        int x = order[n-1-i];
        if(!vis[x]){
            dfs(x, rg);
            scc++;
        }
    }
    return scc;
}

int32_t main(){

}
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 +5;
int arr[N];
int sz[N];
//Dont forget to invoke init in main function.
void init(){
     for(int i=0 ; i< N; i++){
          arr[i] = i;
          sz[i] = 1;
     }
}
//log2(N);
int root(int i){
     while(arr[i]!=i){
          arr[i] = arr[arr[i]];
          i = arr[i];
     }
     return i;
}
//Note: for root i always arr[i] = i;
//also log2(N)
void union1(int a, int b){
     int root_a = root(a);
     int root_b = root(b);
     if(root_a == root_b) // that means already connected
          return;
     else if(sz[root_a] < sz[root_b]){
          arr[root_a] = arr[root_b];
          sz[root_b]+=sz[root_a];
          //set contains 0 elements now onwards.
          sz[root_a] = 0; 
     }
     else{
          arr[root_b] = arr[root_a];
          sz[root_a]+=sz[root_b];
          //set contains 0 elements now onwards.
          sz[root_b] = 0;
     }
}
bool find(int a,int b)
{
     if( root(a)==root(b) )   
     return true;
     else
     return false;
}


//For checking cycle 
//for each of the edges check root(a) == root(b) or not ? if it is true then graph contains cycle.

signed main(){

}
#include<iostream>
#include<vector>
using namespace std ;

int main(){
     int n , m;
     cin >> n >> m;

     vector<vector<int>> arr(n+1);
     for (int i=0;i<m;i++){
          int u , v;     
          cin >> u >> v;

          arr[u].push_back(v);
          arr[v].push_back(u);

     }
     
     return 0;
}
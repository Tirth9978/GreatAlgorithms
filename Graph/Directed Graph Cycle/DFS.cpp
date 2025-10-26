class Solution {
  public:
    
    bool DFS( vector<vector<int>> graph , vector<int> & visited , vector<int> & path , int node) {
        visited[node] = 1;
        path[node] = 1;
        
        for (int i = 0 ;i <graph[node].size() ;i ++) {
            if (!visited[graph[node][i]]) {
                if (DFS(graph , visited , path , graph[node][i]) ) return true ; 
            }
            else if (path[graph[node][i]]){
                return true ;
            }
        }
        
        path[node] = 0;
        return false ;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> graph(V);
        for (auto &e : edges)
            graph[e[0]].push_back(e[1]);
            
            
        vector<int> visited(V , 0);
        vector<int> path(V , 0);
        
        for (int i=0;i<V ;i ++) {
            if (!visited[i]){
                if (DFS(graph , visited , path  , i) ) return true ; 
            }
        }
        return false ;
    }
};
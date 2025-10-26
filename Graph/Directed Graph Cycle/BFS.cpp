class Solution {
  public:
    
    int BFS(vector<vector<int>> & graph , vector<int> & ind ,queue<int> & q ) {
        int count =0;
        while (!q.empty()) {
            int node = q.front();
            q.pop() ; 
            
            count ++ ;
            
            for (auto x : graph[node]){
                ind[x]--;
                if (ind[x] == 0) {
                    q.push(x);
                }
            }
        }
        return count ; 
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> graph(V);
        for (auto &e : edges)
            graph[e[0]].push_back(e[1]);
            
        vector<int> ind(V , 0);    
        queue<int> q ;
        for (int i =0 ;i <graph.size() ;i ++) {
            for (int j =0 ;j<graph[i].size() ;j++) {
                ind[graph[i][j]] ++ ;
            }
        }
        
        for (int i =0;i<V;i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
        }
        
        if (BFS(graph , ind, q) < V) {
            return 1;
        }
        return 0;
        
        
    }
};
class Solution {
  public:
    
    void goTodfs(vector<vector<int>>& adj,int node ,vector<int>& visited ,vector<int> & ans){
        
        visited[node] = 1;
        ans.push_back(node);
        for (int i=0;i<adj[node].size();i++){
            if (!visited[adj[node][i]]){
                goTodfs(adj ,adj[node][i] , visited , ans );
            }
        }
        
        return ;
    }
        
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> visited(adj.size() , 0);
        visited[0] = 1;
        vector<int> ans; 
        
        goTodfs(adj , 0 , visited , ans);
        
        return ans; 
    }
};
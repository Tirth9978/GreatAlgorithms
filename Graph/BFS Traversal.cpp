class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int visited[adj.size()] = {0};
        
        queue<int> q;
        visited[0] = 1;
        q.push(0);
        
        vector<int> ans ;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for (int i=0;i<adj[front].size() ; i++){
                if (!visited[adj[front][i]]){
                    visited[adj[front][i]] = 1;
                    q.push(adj[front][i]);
                }
            }
            ans.push_back(front);
        }
        return ans ;
    }
};
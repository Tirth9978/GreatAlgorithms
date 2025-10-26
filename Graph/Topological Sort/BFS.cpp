class Solution {
    
    
    public:
    
    void BFS(vector<vector<int>> & graph , vector<int> & ind , vector<int> & ans , queue<int> & q ) {
        while (!q.empty()){
            int node = q.front() ; 
            q.pop();
            ans.push_back(node);
            
            for (auto x : graph[node]) {
                
                ind[x]-- ;
                if (ind[x] == 0){
                    q.push(x);
                }
                
            }
        }
        return ;
    }    
        
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph (V);
       
        for (int i= 0 ;i <edges.size() ; i++){
            graph[edges[i][0]].push_back(edges[i][1]);
        }
       
        vector<int> ans ; 
        vector<int> ind (V ,  0); 
        queue<int> q ; 
        
        for (int i =0 ;i <graph.size() ; i ++) {
            for (int j = 0;j<graph[i].size() ; j++){
                ind[graph[i][j]] ++;    
            }
        }
        
        for (int i =0 ;i <V;i++) {
            if (ind[i] == 0){
                q.push(i);
            }
        }
        
        BFS(graph , ind , ans , q);
        
        return ans ;
    }
};
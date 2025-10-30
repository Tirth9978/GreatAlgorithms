class Solution {
  public:
  
    int BFS(vector<vector<int>> & graph , vector<int> & ind , queue<int> q ) {
        int count = 0 ;
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            
            count ++ ;
        
            for (auto x : graph[node]){
                ind[x] -- ;
                if (ind[x] == 0){
                    q.push(x);
                }
            }
        }
        
        return count ;
    }
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        vector<vector<int>> graph(N) ;
        for (int i =0 ;i <prerequisites.size() ;i++) {
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        
        int count = 0;
        vector<int> ind(N , 0);
        for (int i =0;i<graph.size() ;i++ ) {
            for (auto x : graph[i]){
                ind[x] ++ ;
            }
        }
        
        queue<int> q;
        for (int i=0;i<N;i++){
            if (ind[i] == 0) {
                q.push(i);
            }
        }
        
        if (BFS(graph , ind , q ) !=N){
            return false;
        }
        return true;
    } 
};
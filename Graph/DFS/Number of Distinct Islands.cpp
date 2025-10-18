// User function Template for C++

class Solution {
  public:
  
    void DFS(vector<vector<int>>& grid , vector<vector<bool>>& visited , int i ,int j , pair<int ,int> base ,vector<pair<int,int>>& info) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]){
            return ;
        }
        info.push_back({i - base.first ,  j - base.second});
        visited[i][j] = true ; 
        
        int forI[] = {-1 , 0 , 1 , 0};
        int forJ[] = {0 , -1 , 0 , 1};
        
        for (int k=0;k<4;k++){
            int newI = forI[k] + i  ;
            int newJ = forJ[k] + j;
            DFS(grid , visited , newI ,  newJ,base , info);
        }
        return ;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size() , vector<bool> (grid[0].size() , false)) ;
        set<vector<pair<int,int>>> s ;
        for (int i =0 ; i<grid.size() ; i++){
            for (int j =0;j<grid[0].size() ; j++){
                if (!visited[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> info ; 
                    DFS(grid , visited , i ,  j,{i,j} , info );
                    s.insert(info);
                }
            }
        }
        return s.size();
    }
};

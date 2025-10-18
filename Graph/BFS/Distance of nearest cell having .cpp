class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size() , vector<bool> (grid[0].size() , false));
        vector<vector<int>> ans (grid.size() , vector<int> (grid[0].size() , 0));
        queue<pair<pair<int,int> , int>> q;
        
        for (int i=0;i<grid.size() ; i++){
            for (int j=0;j<grid[0].size() ; j++){
                if (grid[i][j] == 1){
                    q.push({{i , j} , 0});
                    ans[i][j] = 0 ; 
                    visited[i][j] = true;
                }
            }
        }
        
        while(!q.empty()){
            // pair<pair<int,int> , int>  p = q.front() ;
            
            int ith = q.front().first.first ;
            int jth = q.front().first.second ;
            int dis = q.front().second ; 
            q.pop();
            
            int forI[] = {-1 , 0 , 1,0};
            int forJ[] = {0 , 1 , 0 , -1};
            ans[ith][jth] =  dis;
            for (int i  =0;i<4 ; i ++){
                int newI = ith + forI[i];
                int newJ = jth + forJ[i] ;  
                if (newI >= 0 && newJ >= 0 && newI < grid.size() && newJ < grid[0].size() && grid[newI][newJ] == 0 && !visited[newI][newJ]){
                    q.push({{newI , newJ} , dis + 1});
                    visited[newI][newJ] = true;
                }
            }
        }
        return ans ;
    }
};





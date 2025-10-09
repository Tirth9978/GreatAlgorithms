class Solution {
public:

    void BFS(vector<vector<char>>& grid , vector<vector<bool>>& visited,int i1, int j1){
        visited[i1][j1] = true;

        queue<pair<int,int>> q;
        q.push({i1,j1});
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            int forI[] = {-1 , 0 , 1 ,0};
            int forJ[] = {0 , 1 , 0 , -1};

            int i2 = p.first ;
            int j2 =  p.second ;

            for (int i=0;i<4;i++){
                int nI = i2 + forI[i];
                int nJ =  j2 + forJ[i];
                if (nI >= 0 && nJ >= 0 && nI < grid.size() && nJ < grid[0].size()){
                    if (!visited[nI][nJ] && grid[nI][nJ] == '1'){
                        q.push({nI , nJ});
                        visited[nI][nJ] = true;
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool> (grid[0].size() , false));
        int count =0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                if (grid[i][j]=='1' && !visited[i][j]){
                    BFS(grid , visited , i , j );
                    count ++;
                }
            }
        }
        return count ;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int> , int>> q;
        vector<vector<bool>> visited(grid.size() , vector<bool> (grid[0].size() , false ));
        for (int i=0;i<grid.size();i++){
            for (int j =0;j<grid[0].size() ; j++){
                if (grid[i][j] == 2){
                    q.push({{i , j} , 0});
                }
            }
        }

        int mn = 0;
        while(!q.empty()) {
            pair<pair<int,int> , int> p = q.front();
            q.pop();

            int i = p.first.first;
            int j = p.first.second;
            int time = p.second ;

            mn = max(time , mn);

            int forI[] = {-1 , 0 , 1 , 0};
            int forJ[] = {0 , 1 , 0 , -1};

            for (int k=0;k<4;k++){
                int ith = i + forI[k];
                int jth = j + forJ[k];

                if (ith >=0 && jth >= 0 && ith < grid.size() && jth < grid[0].size() && !visited[ith][jth] && grid[ith][jth] == 1){
                    q.push({{ith , jth} , time+ 1});
                    visited[ith][jth] = true;
                    grid[ith][jth] = 2;
                }
            }
        }
        for (int i=0;i<grid.size();i++){
            for (int j =0;j<grid[0].size() ; j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return mn;
    }
};
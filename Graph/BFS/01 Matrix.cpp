class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<bool>> visited(mat.size() , vector<bool>(mat[0].size() , false));
        vector<vector<int>> dis(mat.size() , vector<int> (mat[0].size(),-1));

        queue<pair<pair<int,int>,int>> q;
        for (int i=0;i<mat.size();i++){
            for (int j=0;j<mat[0].size();j++){
                if (mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j] = true ; 
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second ;
            int dist = q.front().second;
            q.pop();

            dis[i][j] = dist;

            int forI[] = {-1 , 0 , 1 , 0};
            int forJ[] = {0 , 1 , 0 , -1};

            for (int k = 0;k<4;k++){
                int newI = i + forI[k];
                int newJ = j+forJ[k];

                if (newI>=0 && newJ>=0 && newI <mat.size() && newJ < mat[0].size() && !visited[newI][newJ]){
                    q.push({{newI,newJ} , dist+1});
                    visited[newI][newJ] = true; 
                }
            }
        }
        return dis ; 
    }
};

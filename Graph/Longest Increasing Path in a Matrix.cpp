class Solution {
public:
    int DFS(vector<vector<int>> & matrix , vector<vector<int>> & dp,vector<vector<bool>> & vi,int i,int j){
        if (dp[i][j] != -1){
            return dp[i][j];
        }
        int forI[] = {-1,0,1,0};
        int forJ[] = {0,1,0,-1};

        int ans = 0;
        for(int ith=0;ith<4;ith ++){
            int newI = i + forI[ith];
            int newJ = j + forJ[ith];

            if (newI >= 0 && newJ >=0 && newI < matrix.size() && newJ < matrix[0].size() && matrix[newI][newJ]>matrix[i][j] ){   
                ans=max(ans,DFS(matrix  , dp,vi , newI,newJ));
            }
            // else if (newI >= 0 && newJ >=0 && newI < matrix.size() && newJ < matrix[0].size() && matrix[newI][newJ]!=matrix[i][j] + 1){
            //     return 0;
            // }
        }
        return dp[i][j] =  ans + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<bool>> vi(matrix.size() , vector<bool>(matrix[0].size(),false));
        vector<vector<int>> dp(matrix.size() , vector<int>(matrix[0].size() , -1));

        int ans = 0;
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                ans=max(ans , DFS(matrix ,dp, vi , i  , j));
            }
        }
        return ans ;
    }
};
class Solution {
public:
    int solve(vector<vector<int>>& matrix , vector<vector<int>> & dp , int i,int j){
        if (j < 0 || j >= matrix[0].size()) {
            return 1e9;
        }
        if (i == 0) {
            return matrix[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        return dp[i][j] = min(matrix[i][j] + solve(matrix, dp , i-1,j-1) , min(matrix[i][j] + solve(matrix,dp,i-1,j) , matrix[i][j] + solve(matrix , dp , i-1 , j+1)));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size() , vector<int> (matrix[0].size(),-1));
        int ans = INT_MAX;
        for (int i=0;i<matrix[0].size() ;i ++) {
            ans = min(ans , solve(matrix , dp , matrix.size()-1 , i));
        }
        return ans ;
    }
};
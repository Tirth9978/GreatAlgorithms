class Solution {
public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() ;
        int m = text2.size();

        vvt dp(n+1 , vt(m+1,0));
        for (int i=1;i<n+1;i++){
            for (int j=1;j<m+1;j++){
                if (text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

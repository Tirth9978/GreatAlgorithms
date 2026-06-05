class Solution {
public:
    using vt = vector<int>;
    using vvt = vector<vector<int>>;

    int solve(vvt & dp , string &word1, string &word2,int i ,int j){
        if (i == -1 || j == -1){
            return abs(i-j);
        }   
        if (dp[i][j] != -1) return dp[i][j];
        if (word1[i] == word2[j]){
            return solve(dp, word1,word2, i-1,j-1);
        }

        int insert = 1 + solve(dp , word1 , word2 , i,j-1);
        int Delete = 1 + solve(dp , word1 , word2 , i-1,j);
        int replace = 1 + solve(dp , word1 , word2 , i-1,j-1);
        return dp[i][j] =  min({insert ,Delete , replace});
    }
    int minDistance(string word1, string word2) {
        if (word1 == word2){
            return 0;
        }
        
        vvt dp(word1.size(), vt(word2.size(),-1));
        return solve(dp ,word1,word2 , word1.size()-1 , word2.size()-1);
    }
};

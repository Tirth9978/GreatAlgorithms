class Solution {
public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    int minDistance(string word1, string word2) {
        vvt dp(word1.size()+1 , vt (word2.size()+1 , 0));

        for (int i=0;i<word1.size()+1;i++){
            dp[i][0] = abs(i);
        }
        for (int j= 0; j<word2.size()+1;j++){
            dp[0][j] = abs(j);
        }

        for (int i=1;i<word1.size()+1 ;i++){
            for (int j=1;j<word2.size()+1;j++){
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min({dp[i][j-1]+1 , dp[i-1][j] +1 , dp[i-1][j-1]+1});
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

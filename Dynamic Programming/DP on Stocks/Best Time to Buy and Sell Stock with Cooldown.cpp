class Solution {
public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    int maxProfit(vector<int>& prices) {
        vvt dp(prices.size()+2 , vt(2,0));

        for (int i=prices.size()-1;i>=0;i--){
            for (int j=0;j<2;j++){
                if (j) {
                    dp[i][j] = max(-prices[i] + dp[i+1][0] , dp[i+1][1]);
                }
                else {
                    dp[i][j] = max(prices[i] + dp[i+2][1] , dp[i+1][0]);
                }
            }
        } 
        return dp[0][1];
    }
};

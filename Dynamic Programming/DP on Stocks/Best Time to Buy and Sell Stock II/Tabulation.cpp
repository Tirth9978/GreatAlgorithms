class Solution {
public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    
    int maxProfit(vector<int>& prices) {
        vvt dp(prices.size()+1,vt(2,0));
        for (int i =prices.size()-1;i>-1;i--){
            dp[i][1] = max(dp[i+1][1] , -prices[i] + dp[i+1][0]);
            dp[i][0] = max(dp[i+1][0] , prices[i] + dp[i+1][1]);
        }
        return dp[0][1];
    }
};

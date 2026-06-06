class Solution {
public:
    using vt = vector<int>;
    int maxProfit(vector<int>& prices) {
        vt dp(prices.size(),0);
        for (int i=1;i<prices.size();i++){
            dp[i] = min(dp[i-1] , prices[i]);
        }
        int mn = dp[i];
        for (int i =0;i<dp.size();i++){
            mn = min(prices[i]-dp[i]);
        }
        return mn;
    }
};

class Solution {
public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    int solve(vector<int>& prices , int i,int buy, vvt & dp){
        if (i == prices.size()){
            return 0;
        }
        if (dp[i][buy] != -1){
            return dp[i][buy];
        }
        int profit = 0;
        // Buy 
        if (buy) {
            profit = max(-prices[i] + solve(prices ,i+1 , 0,dp) , 0+ solve(prices , i+1,1,dp));
        }
        //Sell
        else {
            profit = max(prices[i] + solve(prices , i+1,1,dp) , 0+solve(prices , i+1 ,0,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vvt dp(prices.size(),vt(2,-1));
        return solve(prices , 0 , 1 , dp);
    }
};

class Solution {
public:
    using vvvt = vector<vector<vector<int>>>;
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    
    int maxProfit(vector<int>& prices) {
        vvvt dp(prices.size()+1 ,vvt(2 , vt(3,0)));
        for (int i=prices.size()-1;i>=0;i--){
            for (int buy = 0;buy<2;buy++){
                for (int cap = 1;cap<3;cap++) {
                    if (buy){
                        dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap] , dp[i+1][1][cap]);
                    }
                    else {
                        dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1] , dp[i+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};

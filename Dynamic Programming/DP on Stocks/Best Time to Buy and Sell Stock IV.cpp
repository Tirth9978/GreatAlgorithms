class Solution {
public:
    using vvvt = vector<vector<vector<int>>>;
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    int maxProfit(int k, vector<int>& prices) {
        vvvt dp(prices.size()+1 , vvt(2 , vt(k+1 , 0)));

        for (int i=(int) prices.size()-1;i>=0;i --){
            for (int j=0;j<2;j++){
                for (int l=1;l<k+1;l++){
                    if (j) {
                        dp[i][j][l] = max(-prices[i] + dp[i+1][0][l] , dp[i+1][j][l]);
                    }
                    else {
                        dp[i][j][l] = max(prices[i] + dp[i+1][1][l-1] , dp[i+1][j][l]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};

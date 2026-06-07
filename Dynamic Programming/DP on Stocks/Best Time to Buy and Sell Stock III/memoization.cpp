class Solution {
public:
    using vvvt = vector<vector<vector<int>>>;
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    int solve(vector<int>& a, vvvt & dp , int i,int buy ,int count){
        if (count == 0|| i == a.size()){
            return 0;
        }
        if (dp[i][buy][count] != -1) return dp[i][buy][count];
        int profit = 0;
        if (buy) {
            profit = max(-a[i] + solve(a , dp , i+1 , 0 ,count) , solve(a , dp,i+1,1,count));
        }

        else {
            profit = max(a[i] + solve(a,dp , i+1 , 1 , count -1) , solve(a , dp , i+1,0,count));
        }
        return dp[i][buy][count] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vvvt dp(prices.size() ,vvt(2 , vt(3,-1)));
        return solve( prices, dp , 0 , 1, 2);
    }
};

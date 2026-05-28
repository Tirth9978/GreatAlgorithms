class Solution {
  public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vvt dp(val.size() , vt(W+1,0));
        
        for (int i=0;i<W+1;i++){
            if (i>=wt[0]){
                dp[0][i] = val[0];
            }
        }
        
        for (int i=1;i<dp.size();i++){
            for (int j =0;j<W+1;j++) {
                int notPick = dp[i-1][j];
                int pick = 0;
                if (j >= wt[i]) {
                    pick = dp[i-1][j-wt[i]] + val[i];
                }
                dp[i][j] += max(pick , notPick);
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

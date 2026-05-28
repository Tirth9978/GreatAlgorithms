class Solution {
  public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    
    
    int solve(vector<int> &val, vector<int> &wt ,vvt& dp, int i ,int W){
    
        if (i ==0) {
            if (wt[0] <= W) return val[0];
            else return 0;
        }
        if (dp[i][W] != -1) return dp[i][W];
        
        int notPick = solve(val , wt ,dp, i-1,W);
        int pick = 0;
        if (W >= wt[i]) {
            pick = solve(val , wt ,dp, i-1,W-wt[i]) + val[i]; 
        }
        
        return dp[i][W] = max(pick,notPick);
        
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vvt dp(val.size() , vt(W+1 , -1));  
        return solve(val,wt,dp , val.size()-1,W);
    }
};

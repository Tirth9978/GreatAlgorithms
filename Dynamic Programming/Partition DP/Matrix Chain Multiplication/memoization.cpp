class Solution {
  public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    
    int solve(vvt & dp , vt & arr , int i,int j){
        if (i == j){
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        
        int mn = 1e9;
        for (int k=i;k<j;k++) {
            int steps =( arr[i-1] * arr[k] * arr[j] )+ solve(dp , arr , i , k) + solve(dp , arr , k+1 , j);
            mn = min(mn , steps);
        }
        
        return dp[i][j] =  mn ;
    }
    int matrixMultiplication(vector<int> &arr) {
        vvt dp(arr.size(),vt(arr.size(),-1));
        return solve(dp , arr , 1 , arr.size()-1);   
    }
};

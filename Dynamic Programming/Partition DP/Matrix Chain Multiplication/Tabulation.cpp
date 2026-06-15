class Solution {
  public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    int matrixMultiplication(vector<int> &arr) {
        vvt dp(arr.size() , vt(arr.size(),0));
        for (int i=arr.size()-1;i>=1;i--){
            for (int j=i+1;j<arr.size();j++){
                int mn = 1e9;
                for (int k=i;k<j;k++){
                    int steps = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    mn = min(mn , steps);
                }
                dp[i][j] = mn;
            }
        }
        return dp[1][arr.size()-1];
    }
};

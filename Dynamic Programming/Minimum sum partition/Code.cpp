class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int sum =0;
        for (auto x: arr){
            sum+=x;
        }
        
        vector<vector<bool>> dp(arr.size() , vector<bool>(sum+1 , false));
        for (int i=0;i<arr.size();i++) {
            dp[i][0] = true;
        }
        dp[0][arr[0]]= true;
        
        for (int i=1;i<arr.size();i++){
            for (int j =1;j<sum+1;j++) {
                bool notPick = dp[i-1][j];
                bool pick = false;
                if (j>=arr[i]){
                    pick = dp[i-1][j-arr[i]];
                }
                dp[i][j] = pick || notPick ;
            }
        }
        
        int ans = INT_MAX;
        
        for (int i=0;i<sum+1;i++){
            if (dp[dp.size()-1][i])
                ans = min(ans , abs(i-( sum-i)));
        }
        return ans ;
    }
};

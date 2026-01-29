vector<vector<bool>> subsetSumK (vector<int>& nums){
        int sum=0;
        for (auto x : nums)sum+=x;
        vector<vector<bool>> dp(nums.size(),vector<bool> (sum+1,0));

        for(int i=0;i<nums.size();i++){
            dp[i][0] = 1;
        }
        dp[0][nums[0]] = 1;

        for (int i=1;i<nums.size();i++) {
            for(int k=1;k<sum+1;k++){
                bool notTake = dp[i-1][k];
                bool take = false ;
                if(k >= nums[i]) {
                    take = dp[i-1][k-nums[i]];
                }
                dp[i][k] = notTake || take ;
            }
        }

        return dp;
    }

int minSubsetSumDifference(vector<int>& arr, int n)
{
	vector<vector<bool>> dp = subsetSumK(arr);
	int sum = 0;
    for(auto x : arr) sum+=x;
    int mn = 1e9;

	for (int i=0;i<=sum/2;i++){
            if (dp[arr.size()-1][i]) {
                mn = min(mn, abs(sum - 2*i));
            }
        }   
        return mn;
}

class Solution {
public:
    bool solve(vector<int>& nums,vector<vector<int>> & dp,int index,int k) {
        if (index == 0) return nums[index] == k;
        if (k==0) return true;
        if (dp[index][k] != -1){
            if (dp[index][k] == 0) return 0;
            return 1;
        }   
        bool pick = false ;
        bool notPick = false ;

        notPick = solve(nums , dp, index - 1 , k);
        if (k>=nums[index]) {
            pick = solve(nums, dp , index - 1  , k-nums[index]);
        }

        if (pick || notPick){
            dp[index][k] = 1;
            return 1;
        }

        dp[index][k] = 0;
        return 0;
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for (auto x : nums)sum+=x;
        vector<vector<int>> dp(nums.size() , vector<int> ((sum/2) + 1,-1));
        if ((sum&1))return 0;
        return solve(nums , dp , nums.size()-1 , sum / 2 );
    }
};
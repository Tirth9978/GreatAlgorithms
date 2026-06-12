class Solution {
public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    int solve(vt & nums, vvt & dp , int index,int prev_index)   {
        if (index == nums.size())return 0;
        if (dp[index][prev_index+1] != -1) return dp[index][prev_index+1];
        int notPick =0;
         notPick = 0 + solve(nums ,dp , index +1 , prev_index);
        int pick = 0;
        if (prev_index == -1 || nums[index] > nums[prev_index]){
            pick = 1 + solve(nums,dp , index + 1 , index);
        }
        return dp[index][prev_index+1] = max(notPick , pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vvt dp(nums.size()+1 , vt(nums.size()+1 , -1));
        return solve(nums,dp,0,-1);
    }
};

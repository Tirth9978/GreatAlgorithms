class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        vector<unordered_map<int ,int>> dp(n);

        for (int i=1;i<n;i++){
            for (int j=0;j<i;j++) {
                long long diff = static_cast<long long> (nums[i]) - nums[j];
                if (diff > INT_MAX || diff < INT_MIN){
                    continue;
                }

                diff = static_cast<int> (diff);
                dp[i][diff] += 1;
                if (dp[j].count(diff)){
                    dp[i][diff] += dp[j][diff];
                    count += dp[j][diff];
                }
            }
        }
        return count ;
    }
};

class Solution {
public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vvt dp(n + 1, vt(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= -1; j--) {

                int notPick = dp[i + 1][j + 1];

                int pick = 0;
                if (j == -1 || nums[i] > nums[j]) {
                    pick = 1 + dp[i + 1][i + 1];
                }

                dp[i][j + 1] = max(pick, notPick);
            }
        }

        return dp[0][0];
    }
};

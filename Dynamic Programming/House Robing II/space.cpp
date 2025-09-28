class Solution {
public:

    int solve (vector<int> nums , int start , int end){
        int a = 0 , b = 0;
        for (int i = start ; i<= end ; i++){
            int pick  = nums[i] + a ;
            int notPick  = b ;

            int c = max(pick , notPick);

            a = b ;
            b = c;
        }
        return b;
    }
    int rob(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }
        int pick = solve(nums, 0 , nums.size()-2);
        int notPick =  solve(nums, 1 , nums.size()-1);
        return max(pick,notPick);
    }
};
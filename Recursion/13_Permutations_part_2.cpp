// This is the Problem of the Leetcode 

class Solution {
public:
    void getAns (vector<int>& nums , vector<vector<int>> &ans , int start){
        if (start == nums.size()){
            ans.push_back(nums);
            return ;
        }
        for (int i=start ; i < nums.size();i++){
            swap(nums[i] , nums[start]);
            getAns(nums,ans,start + 1);
            swap(nums[i],nums[start]);
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getAns(nums, ans, 0);
        return ans ;
    }
};
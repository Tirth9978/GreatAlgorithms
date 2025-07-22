// This is the Problem of Leetcode 

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() == 1){
            vector<int> ref;
            ref.push_back(nums[0]);
            vector<vector<int>> ans ;
            ans.push_back(ref);
            return ans;
        }

        for (int i=0;i<nums.size();i++){
            int n = nums[i];
            vector<int> ref;
            for (int j=0;j<nums.size();j++){
                if (j != i){
                    ref.push_back(nums[j]);
                }
            }
             vector<vector<int>> perms = permute(ref);
            for (auto x : perms){
                x.insert(x.begin(),n);
                ans.push_back(x);
            }
        }
        return ans;
    }
};
// This is only LeetCode Sol . ..... 

class Solution {
public:

    void ans1(vector<int>& arr ,int target , int index , vector<vector<int>>& ans, vector<int> ds ){
        if (index >= arr.size()){
            if (target == 0){
                ans.push_back(ds);
            }
            return ;    
        }

        if (arr[index] <= target){
            ds.push_back(arr[index]);
            ans1(arr,target-arr[index],index,ans,ds);
            ds.pop_back();
        }
        ans1(arr,target,index+1,ans,ds);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        vector<int> ds;
        ans1(candidates , target , 0,ans ,ds);
        return ans ;
    }
};
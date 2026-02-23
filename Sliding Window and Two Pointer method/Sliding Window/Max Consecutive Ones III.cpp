class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count =0;
        int l = 0;
        int r = 0;
        int ans = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i] == 0)count ++ ;
            if (count > k){
                if (nums[l] == 0)count -- ;
                l ++;
            }
            ans = max(ans, i-l+1);
        }
        return ans ;
    }
};
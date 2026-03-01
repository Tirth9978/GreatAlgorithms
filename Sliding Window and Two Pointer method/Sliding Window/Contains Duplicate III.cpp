class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> st;
        int l =0;
        int r =0;
        while(r<nums.size()){
            if (abs(l-r) > indexDiff) {
                st.erase(nums[l]);
                l++;
            }

            auto it = st.lower_bound(nums[r]-valueDiff);
            if (it!=st.end() && *it<=nums[r] +valueDiff) {
                return 1;
            }
            st.insert(nums[r]);
            r++;
        }
        return 0;
    }
};
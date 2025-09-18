class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        vector<int> ans;
        if (nums.empty()) return ans;

        priority_queue<pair<int,int>> pq;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }

        ans.push_back(pq.top().first);

        for (int i = k; i < nums.size(); i++) {
            pq.push({nums[i], i});

            // remove elements out of this window
            while (!pq.empty() && pq.top().second <= i - k) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

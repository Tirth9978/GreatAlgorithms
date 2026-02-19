class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> st;
        vector<int> ans(arr.size());
        for (int i=arr.size()-1;i>=0;i--){
            while (!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if (st.empty()) {
                st.push(arr[i]);
                ans[i] = -1;
                
            }
            else {
                ans[i] = st.top();
                st.push(arr[i]);
            }
        }
        return ans;
    }
};
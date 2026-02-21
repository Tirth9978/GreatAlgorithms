class Solution {
public:
    vector<int> nextSmaller(vector<int>& arr) {
        vector<int> ans(arr.size());
        stack<int> st ;

        for (int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) ans[i] =(int) arr.size();
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> pervSmaller(vector<int>& arr){
        vector<int> ans(arr.size());
        stack<int> st ;
        for (int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if (st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> NS = nextSmaller(arr);
        vector<int> PS = pervSmaller(arr);
        int mod = 1e9 + 7;
        long long sum = 0;
        for (int i=0;i<arr.size();i++){
            int left = i - PS[i];
            int right = NS[i] - i;
            sum = (sum+  (left * right * 1LL* arr[i]) % mod) % mod;

        }
        return sum ;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i=0;i<asteroids.size();i++){
            if (asteroids[i] > 0) st.push(asteroids[i]);
            else {
                while(!st.empty() && st.top() > 0  && abs(asteroids[i]) > st.top()){
                    st.pop();
                }
                if (!st.empty() && st.top() == abs(asteroids[i])) st.pop();
                else if (st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
            }
        }
        vector<int> ans(st.size());
        int i = ans.size()-1;
        while(!st.empty()){
            ans[i] = st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};
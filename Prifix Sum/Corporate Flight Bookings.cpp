--> class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+1 , 0);
        for (int i=0;i<bookings.size();i++){
            ans[bookings[i][0]-1] += bookings[i][2];
            ans[bookings[i][1]] -= bookings[i][2];
        }

        for (int i=1;i<n;i++) {
            // ans[i-1] -=ans[i];
            ans[i]+=ans[i-1];
        }

        // ans.erase(ans.begin()+n+1);
        ans.pop_back();
        return ans ;
    }
};

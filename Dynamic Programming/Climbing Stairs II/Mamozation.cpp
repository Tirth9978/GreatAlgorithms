class Solution {
public:

    int solve(vector<int> & costs , int index , vector<int> & dp){
        if (index <= 0){
            return dp[index] =  0;
        }
        if (index == 1){
            return dp[index] = costs[1] + 1; 
        }
        
        if (dp[index] != -1){
            return dp[index] ; 
        }

        int one = costs[index] + 1 + solve(costs , index -1, dp);
        int two = INT_MAX;
        int three = INT_MAX;
        if (index >= 2){
            two = costs[index]+ 4  + solve(costs , index -2 , dp);
        }

        if (index >= 3){
            three = costs[index] + 9  + solve(costs , index -3 , dp);

        }
        return dp[index] =  min({one , two , three});

    }

    int climbStairs(int n, vector<int>& costs) {
        costs.insert(costs.begin(), 0); // make it 1-indexed
        vector<int> dp(n+1 , -1);
        return solve(costs , n , dp);
    }
};
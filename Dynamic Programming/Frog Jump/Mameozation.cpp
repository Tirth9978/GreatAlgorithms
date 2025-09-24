#include <bits/stdc++.h> 

int solve(vector<int> &heights , int index , vector<int> & dp){
    if (index == 0){
        return 0;
    }
    if (dp[index] != -1){
        return dp[index];
    }
    int oneJump = solve(heights,index -1,dp) +   abs(heights[index] - heights[index-1]);
    int twoJump = INT_MAX;
    if (index > 1){
        twoJump = solve(heights,index-2,dp) +   abs(heights[index] - heights[index-2]);
        
    }
    return dp[index] =  min(oneJump , twoJump);
}

int frogJump(int n, vector<int> &heights)
{
    if (n == 2){
        return abs(heights[0]- heights[1]);
    }

    vector<int> dp(n,-1);

    return solve(heights , n-1 ,dp);
}
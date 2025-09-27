#include<bits/stdc++.h>

int solve(vector<vector<int>> &points , int day , int last,vector<vector<int>> & dp){
    if (day == 0){
        int maxi = INT_MIN;

        for (int i=0;i<3;i++){
            if (i != last){
                maxi = max(maxi , points[day][i]);
            }
        }
        return dp[day][last] = maxi;
    }

    if (dp[day][last] != -1){
        return dp[day][last] ;
    }

    int maxi  = INT_MIN;
    for (int i=0;i<3;i++){
        int point = 0;
        if (i != last){
            point = points[day][i] + solve(points , day -1 , i , dp);
        }
        maxi = max(point , maxi);
    }
    return dp[day][last] = maxi ;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n , vector<int> (4, -1));
    return solve(points , points.size()-1 , 3,dp);
}   
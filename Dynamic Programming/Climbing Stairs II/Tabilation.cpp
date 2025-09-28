int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n , vector<int> (4 , -1));

    dp[0][0] = max(points[0][1] , points[0][2]);
    dp[0][1] = max(points[0][0] , points[0][2]);
    dp[0][2] = max(points[0][1] , points[0][0]);
    dp[0][3] = max(points[0][1] , max(points[0][0] ,points[0][2] ));

    for(int day=1;day<n ; day++){
        for (int last=0;last<4;last++){
            dp[day][last] = 0 ;
            for (int i=0;i<3;i++){
                if (i != last){
                    int ans = points[day][i] + dp[day-1][i];
                    dp[day][last] = max(dp[day][last] , ans);
                }
            }
        }
    } 

    return dp[points.size()-1][3];
}
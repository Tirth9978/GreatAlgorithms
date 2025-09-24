#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,0);
    dp[0] = 0;

    for (int i=1;i<n;i++){
        int oneJump = dp[i-1] + abs(arr[i] - arr[i-1]);
        int twoJump = INT_MAX;

        if (i > 1){
            twoJump = dp[i-2] + abs(arr[i] - arr[i-2]);
        }

        dp[i] = min(oneJump ,twoJump);
    }
    return dp[n-1];
}
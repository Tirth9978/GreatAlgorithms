#include <bits/stdc++.h> 

bool solve(vector<int> &arr , vector<vector<int>> & dp , int index,int k) {
    if (k == 0){
        return true;
    }
    if (index == 0) {
        if (arr[0] == k)return true;
        else return false ; 
    }
    if (dp[index][k] != -1){
        if (dp[index][k] == 0){
            return false;
        }else return true;
    }
    

    bool pick = false ;
    if (arr[index] <= k ){
        pick = solve(arr , dp , index-1 , k - arr[index]);
    }

    bool notPick = solve(arr , dp , index -1 , k);

    if ((pick || notPick)){
        dp[index][k] = 1;
        return true;
    }
    dp[index][k] = 0;
    return false ;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n , vector<int>(k+1 , -1));
    return solve(arr , dp , n-1 , k);
}
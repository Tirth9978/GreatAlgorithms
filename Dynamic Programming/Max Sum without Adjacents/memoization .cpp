// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int solve(vector<int> & arr , int index, vector<int> & dp){
        if (index == -1){
            return 0;
        }
        if (index == 0){
            return arr[0];
        }
            
        if (dp[index] != -1){
            return dp[index] ;
        }
            
        int pick = solve(arr , index -2 , dp);
        int notPick = solve(arr , index -1,dp);
        
        if (pick + arr[index] > notPick){
            return dp[index] =  pick + arr[index] ;
        }
        return dp[index] = notPick;
    }
    int findMaxSum(vector<int>& arr) {
        vector<int> dp(arr.size() , -1) ;
        return solve(arr , arr.size()-1 ,dp);
    }
};
// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int solve(vector<int> & arr , int index){
        if (index == -1){
            return 0;
        }
        if (index == 0){
            return arr[0];
        }
        
        int pick = solve(arr , index -2);
        int notPick = solve(arr , index -1);
        
        if (pick + arr[index] > notPick){
            return pick + arr[index] ;
        }
        return notPick;
    }
    int findMaxSum(vector<int>& arr) {
        return solve(arr , arr.size()-1);
    }
};
// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        int a = arr[0];
        int b = max(arr[1] , arr[0]);
        int ans = 0;
        for (int i=2;i<arr.size();i++){
            int c = arr[i] + a;
            if (arr[i] + a > b){
                c = arr[i] + a;
            }
            else {
                c = b;
            }
            a = b;
            b = c;
        }
        return b ;
    }
};
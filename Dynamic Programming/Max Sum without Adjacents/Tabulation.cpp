
// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        vector<int> ref(arr.size());
        
        ref[0] = arr[0];
        ref[1] = max(arr[0],arr[1]);
        
        for (int i=2;i<arr.size();i++){
            int pick = arr[i] + ref[i-2];
            int notPick =  ref[i-1];
            
            if (pick > notPick){
                ref[i] = pick; 
            }
            else {
                ref[i] = notPick;
            }
        }
        return ref[ref.size()-1];
    }
};
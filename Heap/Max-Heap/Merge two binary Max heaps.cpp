// User function Template for C++

class Solution {
  public:
  
    void solve(vector<int> & arr ){
        int index = arr.size()-1;
        while(arr[index] > arr[(index-1)/2]){
            swap(arr[index] , arr[(index -1)/2]);
            index = (index-1)/2;
        }
        return ;
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        for (int i=0;i<b.size();i++){
            a.push_back(b[i]);
            solve(a);
        }
        return a;
    }
};
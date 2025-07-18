#include<iostream>
#include<vector>
using namespace std ;

vector<int> merge(vector<int> arr) {
     if (arr.size() == 1){
          return arr;
     }


     int mid = arr.size() / 2;
     vector<int> sliced_left(arr.begin(), arr.begin() + mid);
     vector<int> sliced_right(arr.begin() + mid, arr.end());

     // vector<int> sliced_left(arr.begin() , arr.begin() + (arr.size() / 2) + 1 );
     vector<int> left = merge(sliced_left);

     // vector<int> sliced_right(arr.begin() + (arr.size() /2) + 1  , arr.end());
     vector<int> right = merge(sliced_right);

     int j = 0; 
     int i = 0;
     vector<int> ans;
     while(i < left.size() && j < right.size()){
          if (left[i] < right[j]){
               ans.push_back(left[i]);
               i++;
          }else {
               ans.push_back(right[j]);
               j++;
          }
     }
     while(i < left.size()){
          ans.push_back(left[i]);
          i++;
     }
     while(j < right.size()){
          ans.push_back(right[j]);
          j ++ ;
     }
     return ans ;

}    

int main(){
     int n ;
     cin >> n;

     vector<int> arr(n);   
     for (int i=0;i<n;i++){
          cin >> arr[i];
     }
     cout << 1 << endl;
     vector<int> ans = merge(arr);
     
     for (int i=0;i<ans.size();i++){
          cout << ans[i] << " ";
     }

     cout << endl;
     return 0;
}
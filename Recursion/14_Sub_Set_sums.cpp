#include <iostream>
#include <vector>
using namespace std;
void sums(vector<int> arr, int sum,vector<int> & ans,int index){
     if (index >= arr.size()){
          ans.push_back(sum);
          return ;
     }

     // Pick 
     sum += arr[index];
     sums(arr,sum , ans,index + 1);

     // Not Pick
     sum -= arr[index] ;
     sums(arr,sum , ans,index+1);

     return ;
}
int main(){
     int n;
     cin >> n;
     vector<int> arr(n);
     for (int i = 0; i < n; i++){
          cin >> arr[i];
     }
     vector<int> ans ;

     sums(arr,0,ans,0);
     for (int i=0;i<ans.size();i++){
          cout << ans[i] << " ";
     }
     
     return 0;
}
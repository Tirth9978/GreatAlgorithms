#include<iostream>
#include<vector>
using namespace std ;

void Rev(vector<int> & arr,int i) {
     if(i == arr.size() /2 ){
          return ;
     }

     int temp = arr[i];
     arr[i] = arr[arr.size()- 1 - i];
     arr[arr.size() -1 -i] = temp ;
     Rev(arr, i + 1);
     return ;
}    

int main(){
     int n;
     cin >> n;

     vector<int> arr(n);

     for (int i=0;i<n;i++){
          cin >> arr[i];
     }

     Rev(arr,0);
     for (auto x : arr){
          cout << x << " ";
     }
     return 0;
}
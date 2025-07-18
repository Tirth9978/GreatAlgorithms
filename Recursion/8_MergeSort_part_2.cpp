#include<iostream>
#include<vector>
using namespace std ;

vector<int> mergeArray(vector<int>& arr,int start,int mid , int end) {
     vector<int> ans ;   
     int i = start ;
     int j = mid + 1;

     while(i <= mid && j <= end){
          if (arr[i] < arr[j]){
               ans.push_back(arr[i]);
               i ++ ;
          }else {
               ans.push_back(arr[j]);
               j ++ ;
          }

     }

     while(i <= mid){
          ans.push_back(arr[i]);
          i ++ ;
     }
     while( j <= end){
          ans.push_back(arr[j]);
          j ++ ;
     }
     return ans ;
}

void mergeSort(vector<int>& arr , int start , int end ){
     if (start >= end){
          return ;
     }

     int mid = (start + end) /2 ;
     mergeSort(arr , start , mid);
     mergeSort(arr , mid +1 , end);

     vector<int> merged  = mergeArray(arr,start,mid,end);

     for (int i=start,k =0 ; i<end +1 ;i ++, k++){
          arr[i] = merged[k];
     }
}

int main(){
     int n ;
     cin >> n;

     vector<int> arr(n);   
     for (int i=0;i<n;i++){
          cin >> arr[i];
     }     

     mergeSort(arr, 0 , n-1);
     
     for (int i=0;i<arr.size();i++){
          cout << arr[i] << " ";
     }

     cout << endl;
     return 0;
}
#include<iostream>
using namespace std ;

void swap(int & a, int & b){
     int t = a ;
     a = b;
     b = t ;   
     return ;
}

void heapify(int *arr,int n , int i){
     int largest = i;
     int left = i * 2;
     int right = i * 2 + 1;

     if (left < n && arr[largest] < arr[left] ){
          largest = left;
     }
     if (right < n && arr[largest] < arr[right] ){
          largest = right;
     }

     if (largest != i){
          swap(arr[i],arr[largest]);
          heapify(arr , n , largest);
     }
     return ;
}

int main(){
     int arr[] = {-1,1,2,3,4,5,6,7,8,9};
     int n =10;

     for (int i=n/2 ; i>=1;i--){
          heapify(arr , n , i);
     }
     for (int i=1;i<n;i++){
          cout << arr[i] << " ";
     }
     cout << endl;
     return 0;
}
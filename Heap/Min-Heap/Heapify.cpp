#include<iostream>
using namespace std ;

void swap(int & a, int & b){
     int t = a ;
     a = b;
     b = t ;   
     return ;
}

void heapify(int *arr , int n , int i){
     int large = i;
     int left = 2*i + 1;
     int right = 2*i + 2;

     if (left < n && arr[large] > arr[left]){
          large = left;
     }
     if (right < n && arr[large] > arr[right]){
          large = right ;
     }

     if (large != i){
          swap(arr[i] , arr[large]);
          heapify(arr , n , large);
     }

     return ;
}

int main(){
     int arr[] = {9,8,7,6,5,4,3,2,1};
     int n =  9;

     for (int i = n/2 ; i>=0;i--){
          heapify(arr , n , i);
     }

     for (auto x : arr){
          cout << x << " ";
     }

     return 0;
}
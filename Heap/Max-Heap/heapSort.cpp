#include<iostream>
using namespace std ;

void swap(int & a, int & b){
     int t = a ;
     a = b;
     b = t ;   
     return ;
}

void heapify(int *arr , int n ,int i){
     int large = i;
     int left = i*2 +1;
     int right = i*2 + 2;

     if (left < n && arr[large] < arr[left]){
          large = left;
     }
     if (right < n && arr[large] < arr[right]) {
          large = right;
     }

     if (large != i){
          swap(arr[large], arr[i]);
          heapify(arr ,n,large);
     }
     return ;
}

int main(){
     int arr[] = {70,60,55,45,50};
     int n = 5;
     int size = 5;
     while(size != 0){
          swap(arr[0] , arr[size-1]);
          size -- ;
          heapify(arr , size , 0);
     }

     for (auto x : arr){
          cout << x << " "; 
     }cout << endl;
     return 0;
}
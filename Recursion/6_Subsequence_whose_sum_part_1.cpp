#include<iostream>
#include<vector>
using namespace std ;

vector<int> arr ;

void ans(int index, vector<int> ref,int sum ){
     if (index >= arr.size()){
          int ref_sum = 0;
          for (auto x : ref){
               ref_sum += x;
          }
          if (sum == ref_sum ){
               for (int i=0;i<ref.size();i++){
                    cout << ref[i] << " ";
               } 
               cout << endl;
          }
          return ;
     }

     ref.push_back(arr[index]);
     ans(index + 1 , ref,sum);

     ref.pop_back();
     ans(index + 1 , ref, sum);
     return ; 
}

int main(){
     int n;
     cin >> n ; 
     for (int i=0;i<n;i++){
          int num ;
          cin >> num ;
          arr.push_back(num);
     }
     
     vector<int> ref;
     ans(0 , ref , 2);
     return 0;
}
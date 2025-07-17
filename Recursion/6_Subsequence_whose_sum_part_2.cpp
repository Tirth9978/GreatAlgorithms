#include<iostream>
#include<vector>
using namespace std ;

vector<int> arr ;
int sum ;

void ans(int index, vector<int> ref,int ref_sum ){
     if (index >= arr.size()){
          if (ref_sum == sum){
               for (int i=0;i<ref.size();i++){
                    cout << ref[i] << " ";
               }
               cout << endl;
          }
          return ;
     }

     ref.push_back(arr[index]) ;
     ref_sum += arr[index];
     ans(index + 1 , ref,ref_sum);

     ref.pop_back();
     ref_sum -= arr[index] ;
     ans(index + 1 , ref,ref_sum);
     return;
}

int main(){
     int n;
     cin >> n ; 
     for (int i=0;i<n;i++){
          int num ;
          cin >> num ;
          arr.push_back(num);
     }

     cin >> sum ;
     vector<int> ref;
     ans(0 , ref , 0);
     return 0;
}
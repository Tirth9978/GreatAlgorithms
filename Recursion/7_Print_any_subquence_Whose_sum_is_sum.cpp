#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int sum;

bool ans(int index, vector<int> ref, int ref_sum){
     if (index >= arr.size()){
          
          if (ref_sum == sum){
               cout << "ai";
               for (int i=0;i<ref.size();i++){
                    cout << ref[i] << " ";
               }
               cout << endl;
               return true;

          }
          return false ;
     }

     //Taking
     ref.push_back(arr[index]);
     ref_sum += arr[index];

     if(ans(index + 1 , ref,ref_sum)) {
          return true;
     }
     
     ref.pop_back();
     ref_sum -=arr[index] ; 
     if (ans(index + 1 , ref,ref_sum)) {
          return true;
     }
     return false;
}

int main(){
     int n;
     cin >> n;
     for (int i = 0; i < n; i++)
     {
          int num;
          cin >> num;
          arr.push_back(num);
     }

     cin >> sum;
     vector<int> ref;
     bool find = ans(0, ref, 0);

     return 0;
}
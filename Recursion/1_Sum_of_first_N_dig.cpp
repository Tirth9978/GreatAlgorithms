#include<iostream>
using namespace std ;

int sum(int n) {
     if (n == 0){
          return 0 ;
     }
     int ans = sum(n-1);
     ans += n ;
     return ans ;
}    

int main(){
     int n;
     cin >> n;
     cout << sum(n) << endl;
     return 0;
}
#include<iostream>
#include<vector>
using namespace std ;

int fb(int n , vector<int> & dp){
     if (n <= 1){
          return n;
     }

     if (dp[n] != -1){
          return dp[n];
     }

     int ans = fb(n-1 , dp) + fb(n-2 ,dp);

     dp[n] = ans ;
     return ans ;
}

int main(){
     int n;
     cin >> n;
     vector<int> dp(n+1 , -1);

     cout << fb(n , dp) << endl;
     return 0;
}
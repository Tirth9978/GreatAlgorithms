#include<iostream>
#include<cmath>
using namespace std;

int Height(int n){
     if (n == 0){
          return -1;
     }
     return (int)log2(n); // New Thing for me 
}

int main(){
     cout << Height(15) << endl;
     return 0;
}
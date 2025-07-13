#include<iostream>
#include<string>
using namespace std ;

bool isPal(string str,int i){
     if (i == str.size() / 2){
          return true;
     }
     else if (str[i] != str[str.size()-i-1]){
          return false;
     }

     return isPal(str,i+1);
}

int main(){
     string str ;
     cin >> str ;

     if (isPal(str,0)){
          cout << "YES\n";
     }
     else {
          cout << "NO\n";
     }
     return 0;
}
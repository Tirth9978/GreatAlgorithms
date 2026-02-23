#include <bits/stdc++.h>
using namespace std;

int main() {
     unordered_map<string,int> mp;

     vector<string > arr = {"Tirth", "Patel" ,"Tom" , "Patel" , "Rohan"};

     for (auto x : arr){
          mp[x] ++ ;
     }
     for (auto x : mp) {
          cout << x.first << " ==> " << x.second << endl;
     }
     
     cout << mp["Ti"] << endl;
     cout << mp.at("Ti") << endl;
     cout << mp.count("Tirth01") << endl;
     cout << mp.count("Patel") << endl;
     return 0;
}

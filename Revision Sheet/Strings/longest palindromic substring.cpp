#include <iostream>
#include <vector>
using namespace std;

string getLongestPal(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    
    // dp[i][j] if the substring  from [i to j]
    // is a palindrome or not
    
    int start = 0, maxLen = 1;
    
    // all substrings of length 1 are palindromes
    for (int i = 0; i < n; ++i) dp[i][i] = true;
    
    // check for substrings of length 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
              if(maxLen==1){
                    start = i;
                    maxLen = 2;
                }
        }
    }
    
    // check for substrings of length 3 and more
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            
            // if s[i] == s[j] then check for 
            //  i [i+1  --- j-1] j 
            if (s[i] == s[j] && dp[i+1][j-1]) { 
                dp[i][j] = true;
                if(len>maxLen){
                    start = i;
                    maxLen = len;
                }
            }
        }
    }
    return s.substr(start, maxLen);
}

int main() {
    string s = "forgeeksskeegfor";
    cout << getLongestPal(s) << endl; 
}








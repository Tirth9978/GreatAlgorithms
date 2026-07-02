#include <iostream>
#include<vector>
#include<string>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll B = 131;



vector<int> KMP(string s , string p){
    int n = s.size() ;
    int m = p.size() ;

    auto prefixFunction= [&](string s) -> vector<int>  {
        int n = s.size()-1;
        vector<int> pi(n +1 , 0);
        for (int i=2;i<=n;i++){
            int j = pi[i-1];
            while(j > 0 && s[i] != s[j]){
                j = pi[j-1];
            }
            if (s[i] == s[j]) {
                j ++ ;
            }
            pi[i] = j;
        }
        return pi;
    };

    vector<int> ref = prefixFunction(p);
    vector<int> phiTable(ref.size()+1,0);
    for (int i=1;i<phiTable.size();i++)phiTable[i]=ref[i-1];
    
    int i= 0;
    int j =0;
    vector<int> ans;
    while (i < n) {
        while (j > 0 && s[i] != p[j]) {
            j = phiTable[j];
        }

        if (s[i] == p[j]) {
            j++;
        }
        if (j == phiTable.size()-1) {
            ans.push_back(i - (m+1) + 1);
            j = phiTable[j];
        }

        i++;
    }
    return ans;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ACDAB";

    vector<int> result = KMP(text, pattern); 
    for (auto x : result)   {
        cout << x << " ";
    }  
    cout << endl;
    return 0;
}

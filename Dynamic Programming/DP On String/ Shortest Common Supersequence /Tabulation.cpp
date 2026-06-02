class Solution {
public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vvt dp(n+1 , vt(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if (str1[i-1]==str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }

        string ans ="";

        int i = n,j=m;

        while(i>0&&j>0){
            if (str1[i-1] == str2[j-1] ) {
                ans+=str1[i-1];
                i--;j--;
            }
            else if (dp[i-1][j]>dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else {
                ans += str2[j-1];
                j--;
            }
        }
        
        while (i >0) {
            ans += str1[i-1];
            cout << i<<endl;
            i--;
        }
        
        while (j>0) {
            ans+=str2[j-1];
            cout << j << endl;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};

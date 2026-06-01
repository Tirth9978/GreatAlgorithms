class Solution {
  public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    int longCommSubstr(string& s1, string& s2) {
        vvt dp(s1.size() + 1 , vt(s2.size()+1 , 0));
        int ans = 0;
        for (int i=1;i<s1.size()+1 ;i++){
            for(int j=1;j<=s2.size();j++) {
                if (s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = 0;
                
                ans = max(ans , dp[i][j]);
            }
        }
        return ans ;
    }
};

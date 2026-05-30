class Solution {
public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;
    int solve(string &t1,string& t2 , vvt & dp , int i,int j){
        if (i == -1 || j == -1) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (t1[i] == t2[j]) {
            return dp[i][j] =  1 + solve(t1,t2,dp , i-1,j-1);
        }

        return dp[i][j] = 0 + max(solve(t1,t2,dp,i-1,j) , solve(t1,t2,dp,i,j-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vvt dp(text1.size() , vt(text2.size(),-1));

        return solve(text1,text2,dp,text1.size()-1,text2.size()-1);
    }
};

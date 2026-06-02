class Solution {
public:
    using vvt = vector<vector<int>>;
    using vt = vector<int>;

    int solve(vvt & dp , string & s ,string & t , int i ,int j){
        if (j==-1) return 1;
        if (i ==-1)return 0;
        if (dp[i][j] != -1)return dp[i][j];
        if (s[i] == t[j]){
            return solve(dp,s,t,i-1,j-1) + solve(dp , s,t,i-1,j);;
        }
        return dp[i][j]= solve(dp,s,t,i-1,j);
    }

    int numDistinct(string s, string t) {
        vvt dp(s.size(), vt(t.size(),-1));

        return solve(dp,s,t,s.size()-1,t.size()-1);
    }
};

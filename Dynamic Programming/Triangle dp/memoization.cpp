class Solution {
public:

    int solve(vector<vector<int>>& triangle , vector<vector<int>> & dp,int i ,int j) {
        if (i == triangle.size() -1){
            return triangle[i][j];
        }
        if ( j<0|| j > i) {
            return INT_MAX;
        }

        if (dp[i][j] != -1) {
            cout << i <<" "<<  j << endl;
            return dp[i][j];
        }
        int down = triangle[i][j] + solve(triangle , dp , i+1,j);

        int dia = triangle[i][j] + solve(triangle , dp , i +1,j+1);

        return dp[i][j] = min(down , dia);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size() , vector<int> (triangle[triangle.size()-1].size() ,-1));
        return solve(triangle , dp , 0 , 0 );

    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i=1;i<matrix.size();i++) {
            for (int j =0;j<matrix[0].size() ;j++) {
                int one = INT_MAX ;
                int two = INT_MAX ;
                int three = INT_MAX ;

                if (j == 0) {
                    matrix[i][j] = min(matrix[i][j] + matrix[i-1][j] ,matrix[i][j]+ matrix[i-1][j+1]);
                }
                else if (j == matrix[0].size()-1) {
                    matrix[i][j] = min(matrix[i][j] + matrix[i-1][j-1] , matrix[i][j]  + matrix[i-1][j]);
                }else {
                    matrix[i][j] = min(matrix[i][j] + matrix[i-1][j] , min(matrix[i][j] + matrix[i-1][j+1] , matrix[i][j] +  matrix[i-1][j-1]));
                }
            }
        }

        int ans = INT_MAX ;
        for (int i =0;i<matrix[0].size();i++){
            ans = min(ans , matrix[matrix[0].size()-1][i]);
        }
        return ans ;
    }
};
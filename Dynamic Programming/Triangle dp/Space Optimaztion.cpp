class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size()-2 ; i>=0;i--){
            for (int j = i;j>=0;j--) {
                int original = triangle[i][j];
                triangle[i][j] = min(original + triangle[i+1][j+1] , original + triangle[i+1][j]);
            }
        }
        return triangle[0][0];
    }
};
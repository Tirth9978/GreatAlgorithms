class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans (pow(2,n) , 0);
        for (int i=1;i<pow(2,n);i++){
            ans[i] = i ^ (i>>1);
        }
        return ans ;
    }
};
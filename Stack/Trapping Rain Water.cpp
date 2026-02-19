class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int total = 0;
        int Lmax = 0,Rmax = 0;
        while(l < r){
            if (height[l] <= height[r]) {
                if (Lmax > height[l]){
                    total += Lmax - height[l];
                }
                else {
                    Lmax = height[l];
                }
                l++;
            }
            else {
                if (Rmax > height[r]){
                    total += Rmax - height[r];
                }
                else {
                    Rmax = height[r];
                }
                r--;
            }
        }
        return total ;
    }
};
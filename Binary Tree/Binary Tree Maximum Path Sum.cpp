/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int solve(TreeNode * root , int &mx) {
        if (root == NULL){
            return 0;
        }   
        int leftSum = solve(root -> left , mx);
        int rightSum = solve(root -> right , mx);
        if (leftSum < 0){
            leftSum = 0;
        }
        if (rightSum < 0){
            rightSum = 0;
        }
        

        mx = max(mx, root -> val + leftSum + rightSum) ;
        return root -> val + max(leftSum,rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        int ans = solve(root , mx);
        if (root -> val > ans || root-> val > mx){
            return root -> val ;
        }
        if (mx > ans){
            return mx;
        }
        return ans ;
    }
};
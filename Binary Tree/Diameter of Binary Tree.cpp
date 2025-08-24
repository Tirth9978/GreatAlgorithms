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

    int help(TreeNode * root ,  int & ans){
        if (root == NULL){
            return 0;
        }
        int left = help(root->left , ans);
        int right = help(root -> right,ans);

        ans = max(ans,left + right );
        return max(right,left)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int ref = help(root,ans);
        return ans ;
    }
};
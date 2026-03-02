/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxi = INT_MIN;
    int solve(TreeNode* root) {
        if (!root)
            return 0;

        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        maxi = max(maxi, left + right + root->val);

        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int ref = solve(root);
        return maxi;
    }
};
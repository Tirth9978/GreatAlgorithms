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
    bool find(TreeNode * r1 ,TreeNode * r2 ){
        if (r1 == NULL && r2 == NULL){
            return 1;
        }
        if (r1 == NULL || r2 == NULL){
            return 0;
        }

        bool left = find(r1 -> left,r2->right);
        bool right = find (r1->right,r2->left);
        bool diff = r1->val == r2->val;
        return left && right && diff;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL){
            return 1;
        }
        return find (root->left,root->right);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL){
            return NULL ;
        }
        TreeNode * ans ;
        if (root -> val > p -> val && root -> val > q -> val){
            ans =  lowestCommonAncestor(root -> left , p ,q);
        }
        else if (root -> val < p -> val && root -> val < q -> val){
            ans = lowestCommonAncestor(root -> right , p ,q);
        }
        else {
            ans = root ;

        }
        return ans ;
    }
};
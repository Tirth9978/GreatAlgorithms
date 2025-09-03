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

    TreeNode * solve(int mn,int mx , vector<int>& preorder,int & index) {
        TreeNode * root;
        if (index >= preorder.size()){
            return NULL ;
        }
        else if (preorder[index] > mn && preorder[index] < mx){

            root = new TreeNode(preorder[index]);
            index ++ ;
        }
        else {
            return NULL ;
        }

        root -> left = solve(mn , root -> val ,preorder,index);
        root -> right = solve(root -> val , mx , preorder, index);
        return root ;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idex = 0;
        return solve(INT_MIN , INT_MAX,preorder,idex);
    }
};
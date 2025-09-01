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
    TreeNode * maxVal(TreeNode * root ) {
        while(root -> right != NULL){
            root = root -> right ;
        }
        return root  ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL){
            return NULL ;
        }
        if (root -> val == key){

            // 0 Child 
            if (root -> left == NULL && root -> right == NULL){
                return NULL ;
            }

            // 1 Child 
            if (root -> left == NULL && root -> right != NULL){
                TreeNode * temp = root -> right ;
                delete root ;
                return temp;
            }
            if (root -> left != NULL && root -> right == NULL){
                TreeNode * temp = root -> left;
                delete root ;
                return temp ;
            }


            // 2 Child  
            if (root -> left != NULL && root -> right != NULL){
                TreeNode * pre = maxVal(root->left) ;
                root -> val = pre -> val ;
                root -> left =  deleteNode(root -> left , pre -> val);
                return root ;
            }
        }

        if (key < root -> val){
            root -> left = deleteNode(root -> left , key);
            return root ;
        }
        else {
            root -> right = deleteNode(root -> right , key);
            return root;
        }
    }
};
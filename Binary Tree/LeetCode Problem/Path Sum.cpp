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
    void ans (TreeNode * root , int tsum,bool &find,int sum  ){
        if (root==NULL || find){
            return ;
        }
        sum += root->val;
        if(root->left == NULL && root->right == NULL){
            if (sum == tsum){
                find  = 1;
            }
            return ;
        }

        ans (root->left , tsum,find,sum);
        ans(root->right,tsum,find,sum);
        return ;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool find = 0;
        ans(root,targetSum,find,0);
        return find ;
    }
};

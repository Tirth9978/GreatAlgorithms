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

    void getInorder(TreeNode * root , vector<int> & arr){
        if (root == NULL){
            return ;
        }
        getInorder(root -> left , arr);
        arr.push_back(root->val);
        getInorder(root -> right ,arr);

        return ;
    }

    TreeNode * solve(vector<int> &arr, int s , int e){
        if (s > e){
            return NULL ;
        }
        int mid = s + (e-s)/2;
        TreeNode * root = new TreeNode(arr[mid]);

        root -> left = solve(arr, s, mid -1);
        root -> right = solve(arr , mid +1 ,e);

        return root ;
    }
    TreeNode* balanceBST(TreeNode* root){
        vector<int> arr ;
        getInorder(root , arr);

        return solve(arr , 0, arr.size()-1);
    }
};
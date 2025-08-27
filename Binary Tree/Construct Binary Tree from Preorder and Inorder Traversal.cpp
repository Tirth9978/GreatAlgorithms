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

    int findPosition(vector<int>& inorder,int ele) {
        for(int i=0;i<inorder.size();i++){
            if (inorder[i] == ele){
                return i;
            }

        }
        return -1;
    }
    TreeNode * solve(vector<int>& preorder, vector<int>& inorder , int & index , int inorderStart , int inorderEnd,int size ) {
        if (index == size || inorderStart > inorderEnd){
            return NULL ;
        }

        int element = preorder[index++];
        int position = findPosition(inorder,element);
        TreeNode * root = new TreeNode(element);

        root -> left = solve(preorder,inorder,index, inorderStart , position-1,size);
        root -> right = solve(preorder,inorder,index, position+1 ,inorderEnd,size);
        return root ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       
        int index = 0;
        return solve(preorder,inorder,index , 0,inorder.size(),inorder.size());
    }   
};
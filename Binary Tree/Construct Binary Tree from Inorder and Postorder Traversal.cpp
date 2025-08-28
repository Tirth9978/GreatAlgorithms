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
    int getPosition(vector<int>& inorder , int ele){
        for (int i=0;i<inorder.size();i++){
            if (ele == inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode * solve(vector<int>& inorder, vector<int>& postorder , int & index , int startInorder,int endInorder) {
        if (index <= -1 || startInorder > endInorder){
            return NULL;
        }

        int ele = postorder[index--];
        TreeNode * root = new TreeNode(ele);
        int positionIndex = getPosition(inorder,ele);

        root -> right = solve(inorder , postorder , index ,positionIndex + 1 , endInorder);
        root -> left = solve(inorder , postorder , index ,startInorder,positionIndex-1);
        
        return root ;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size()-1;
        TreeNode * ans = solve(inorder , postorder ,index,0,postorder.size()-1);
        return ans ;
    }   
};
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * root = new TreeNode(preorder[0]);
        TreeNode * temp = root;
        stack<TreeNode * > st;
        for (int i=1;i<preorder.size();i++){
            if (preorder[i] < root -> val){
                TreeNode * ptr = new TreeNode(preorder[i]);
                root -> left = ptr;
                st.push(root);
                root = ptr;
            }

            else{
                while(!st.empty() && preorder[i] > st.top()->val){
                    root = st.top();
                    st.pop();
                }

                TreeNode * ptr = new TreeNode (preorder[i]);
                root-> right = ptr;
                root = ptr;
            }
        }
        return temp ;

    }
};

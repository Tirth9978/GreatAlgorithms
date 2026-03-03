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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if (root==NULL)return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool find = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int> ref(size);
            for (int i=0;i<size;i++){
                TreeNode * f = q.front();
                q.pop();

                if (find) ref[i] = f->val;
                else ref[size-i-1] = f->val;

                if (f->left) q.push(f->left);
                if (f->right)q.push(f->right);
            }
            find = !find;
            ans.push_back(ref);
        }
        return ans;
    }
};
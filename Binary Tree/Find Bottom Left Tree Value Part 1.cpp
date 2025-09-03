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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<long long int>> ans;
        vector<long long int> ref; 
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            if (q.front() == NULL){
                q.pop();
                ans.push_back(ref);
                ref.clear();
                if (!q.empty()){
                    q.push(NULL);
                }
                continue;
            }      

            TreeNode * front = q.front();
            ref.push_back(front -> val);
            q.pop();
            if (front -> left){
                q.push(front->left);
            }
            if (front -> right){
                q.push(front -> right);
            }
        }
        return ans[ans.size()-1][0];
    }
};
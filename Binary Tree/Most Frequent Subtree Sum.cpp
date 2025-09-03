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
    map<int ,int> mp;
    int getSum(TreeNode * root){
        if (root == NULL){
            return 0;
        }
        int left = getSum(root -> left);
        int right = getSum(root -> right);

        int sum = left + right + root -> val ;
        mp[sum] ++ ;

        return sum ;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int ref = getSum(root);
        int mxFre = INT_MIN;
        for (auto x : mp){
            mxFre = max(mxFre , x.second);
        }
        vector<int> ans ;
        for (auto x : mp){
            if (x.second == mxFre){
                ans.push_back(x.first);
            }
        }
        return ans ;
    }
};
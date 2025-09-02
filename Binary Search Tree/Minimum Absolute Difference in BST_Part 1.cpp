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
    void solve(TreeNode * root , vector<int>& arr){
        if (root == NULL){
            return ;
        }

        solve(root -> left , arr);
        arr.push_back(root -> val);
        solve(root -> right , arr);
        return ;
    }
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL){
            return 0;
        }

        vector<int> arr ;
        solve(root , arr);
        int ans = INT_MAX;
        for (int i=0;i<arr.size()-1;i++){
            ans = min(ans,arr[i+1] - arr[i]);
        }
        return ans;
    }
};
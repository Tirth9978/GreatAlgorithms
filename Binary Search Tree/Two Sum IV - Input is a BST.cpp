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
    void solve(TreeNode * root ,vector<int>& arr ){
        if (root == NULL){
            return ;
        }

        solve(root -> left , arr);
        arr.push_back(root -> val);
        solve(root -> right , arr);
        return ;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr ;
        solve(root , arr);

        int i =0;
        int j =arr.size()-1;
        while(i < j){
            if (arr[i] + arr[j] == k){
                return 1;
            }
            if (arr[i] + arr[j] > k){
                j --;
            }
            else {
                i ++ ;
            }
        }   
        
        return 0;
    }
};
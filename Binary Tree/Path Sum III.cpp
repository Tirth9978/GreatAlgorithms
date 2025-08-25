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

    void solve(TreeNode* root , int targetSum , vector<int> arr , int & count){
        if (root == NULL){
            return ;
        }

        arr.push_back(root -> val);
        
        long long int sum = 0;
        for (int i=arr.size()-1 ; i>=0;i--){
            sum += arr[i];
            if (sum == targetSum){
                count ++ ;
            }
        }
        solve(root -> left , targetSum , arr , count);
        solve(root -> right , targetSum , arr , count);
        return ;
    }    

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL){
            return 0;
        }
        int count = 0;
        vector<int> arr ;
        solve(root  , targetSum , arr , count);
        return count ; 
    }
};
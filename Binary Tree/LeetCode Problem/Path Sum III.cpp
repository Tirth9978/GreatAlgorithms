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

    void ans(TreeNode * root,int tsum,int & count , vector<int> ref){
        if (root == NULL){
            return ;
        }

        ref.push_back(root->val);

        ans(root->left , tsum,count , ref);
        ans(root->right,tsum,count,ref);

        long long sum =0;
        for (int i=ref.size()-1;i>=0;i--){
            sum+= ref[i];
            if (sum == tsum)count ++;
        }
        ref.pop_back();
        return ;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count =0;
        vector<int> ref;
        ans(root,targetSum,count,ref);
        return count ;
    }
};

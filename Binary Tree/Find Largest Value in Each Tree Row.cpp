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

    void solve(TreeNode * root , int level ,map<int,int> &mp){
        if (root == NULL){
            return ;
        }
        if (mp.find(level) != mp.end()){
            if (mp[level] < root -> val){
                mp[level] = root -> val;
            }
        }
        else {
            mp[level] = root -> val;
        }

        solve(root -> left , level + 1 , mp);
        solve(root -> right , level + 1, mp);

        return ;
    }
    vector<int> largestValues(TreeNode* root) {
        map<int ,int> mp;
        solve(root , 0 , mp);
        vector<int> arr;
        for (auto x : mp){
            arr.push_back(x.second);
        }
        return arr ;
    }
};/**
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

    void solve(TreeNode * root , int level ,map<int,int> &mp){
        if (root == NULL){
            return ;
        }
        if (mp.find(level) != mp.end()){
            if (mp[level] < root -> val){
                mp[level] = root -> val;
            }
        }
        else {
            mp[level] = root -> val;
        }

        solve(root -> left , level + 1 , mp);
        solve(root -> right , level + 1, mp);

        return ;
    }
    vector<int> largestValues(TreeNode* root) {
        map<int ,int> mp;
        solve(root , 0 , mp);
        vector<int> arr;
        for (auto x : mp){
            arr.push_back(x.second);
        }
        return arr ;
    }
};
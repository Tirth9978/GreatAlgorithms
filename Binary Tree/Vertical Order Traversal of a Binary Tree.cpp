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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));

        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp = q.front();
            TreeNode * frontNode = temp.first;
            q.pop();
            int hori = temp.second.first;
            int level = temp.second.second;
            mp[hori][level].push_back(frontNode -> val); 
            if (frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hori-1,level+1)));
            }
            if (frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hori+1,level+1)));
            }
        }
        vector<vector<int>> ans;
        for(auto &x : mp){
            vector<int> ref ;

            for (auto &y : x.second){
                sort(y.second.begin(),y.second.end());
                ref.insert(ref.end(),y.second.begin(),y.second.end());
            }
            ans.push_back(ref);
        }
        return ans;
    }
};

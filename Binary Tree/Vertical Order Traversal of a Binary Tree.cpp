class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp; // hd -> level -> values
        queue<pair<TreeNode*, pair<int,int>>> q; 
        q.push({root, {0,0}}); // node, {hd, level}
        
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            TreeNode* node = p.first;
            int hd = p.second.first;
            int lvl = p.second.second;

            mp[hd][lvl].push_back(node->val);

            if (node->left) q.push({node->left, {hd-1, lvl+1}});
            if (node->right) q.push({node->right, {hd+1, lvl+1}});
        }

        vector<vector<int>> ans;
        for (auto &x : mp) {
            vector<int> col;
            for (auto &y : x.second) {
                auto &vals = y.second;
                sort(vals.begin(), vals.end()); // sort at same level
                col.insert(col.end(), vals.begin(), vals.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

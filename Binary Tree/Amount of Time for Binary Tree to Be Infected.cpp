/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* nodeToParent(TreeNode* root, int start,
                           map<TreeNode*, TreeNode*>& NodeToParent) {
        if (root == NULL) {
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* ans = NULL;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front->val == start) {
                ans = front;
            }
            if (front->left) {
                NodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                NodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return ans;
    }

    int solve(TreeNode* startNode, map<TreeNode*, TreeNode*>& NodeToParent) {
        if (startNode == NULL) {
            return 0;
        }

        int ans = 0;
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int size = q.size();
            bool find = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    find = true;
                    visited[front->left] = true;
                    q.push(front->left);
                }

                // Right child
                if (front->right && !visited[front->right]) {
                    find = true;
                    visited[front->right] = true;
                    q.push(front->right);
                }

                // Parent
                if (NodeToParent[front] && !visited[NodeToParent[front]]) {
                    find = true;
                    visited[NodeToParent[front]] = true;
                    q.push(NodeToParent[front]);
                }
            }
            if (find == 1) {
                ans++;
            }
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> NodeToParent;
        TreeNode* startNode = nodeToParent(root, start, NodeToParent);

        int ans = solve(startNode, NodeToParent);
        return ans;
    }
};
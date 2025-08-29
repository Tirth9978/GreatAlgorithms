class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        queue<Node*> q;
        q.push(root);

        vector<vector<Node*>> arr;

        while (!q.empty()) {
            int size = q.size();
            vector<Node*> level;

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                level.push_back(front);

                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }

            arr.push_back(level);
        }

        // connect each level
        for (auto &level : arr) {
            for (int i = 0; i < (int)level.size() - 1; i++) {
                level[i]->next = level[i+1];
            }
        }

        return root;
    }
};

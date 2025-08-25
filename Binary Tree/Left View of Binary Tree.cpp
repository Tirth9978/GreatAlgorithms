/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
  
    void leftView(Node * root ,vector<int>& ans ,int level){
        if (root == nullptr){
            return ;
        }
        
        if (level == ans.size()){
            ans.push_back(root->data);
        }
        leftView(root->left,ans,level + 1);
        leftView(root->right,ans,level + 1);
        return ;
    }
    vector<int> leftView(Node *root) {
        vector<int> ans ;
        if (root == NULL){
            return ans;
        }
        leftView(root,ans,0);
        return ans ;
    }
};
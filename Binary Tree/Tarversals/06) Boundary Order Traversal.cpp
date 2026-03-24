/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

void forLeft(Node * root , vector<int> & ans){
    if (root==NULL)return ;
    if (root->left == NULL && root ->right == NULL){
        return ;
    }
    ans.push_back(root->data);
    if (root->left) forLeft(root->left , ans);
    else forLeft(root->right , ans);
    
}

void forLeaf(Node * root , vector<int> & ans){
    if (root==NULL) return ;
    if (root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return ;
    }
    forLeaf(root->left, ans);
    forLeaf(root->right , ans);
    return ;
}

void forRight(Node * root , vector<int> & ans){
    if (root==NULL)return ;
    if (root->left == NULL && root->right ==NULL)return ;
    
    
    if (root->right) forRight(root->right , ans);
    else forRight(root->left,ans);
    ans.push_back(root->data);
}

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans ;
        if (root==NULL)return ans;
        ans.push_back(root->data);
        if (root->left == NULL && root->right == NULL)return ans;
        forLeft(root->left, ans);
        forLeaf(root,ans);
        forRight(root->right,ans);
        return ans ;
    }
};
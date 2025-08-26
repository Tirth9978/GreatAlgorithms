/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
  public:
  
    void solve(Node *root, int k, int node,vector<Node * > arr, Node *& ansNode){
        if (root == NULL){
            return ;
        }
        arr.push_back(root);
        if (root -> data == node){
            if (k < arr.size()){
                ansNode = arr[arr.size() - k-1];
            }
            
            return ;
        }
        solve(root->left , k , node ,arr ,ansNode);
        solve(root->right , k , node ,arr ,ansNode);
        return ;
    }
    int kthAncestor(Node *root, int k, int node) {
        if (root == NULL){
            return -1;
        }
        Node * ansNode = NULL;
        vector<Node * > arr ;
        solve(root , k , node , arr , ansNode);
        if (ansNode == NULL){
            return -1;
        }
        return ansNode->data ;
        
    }
};

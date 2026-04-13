/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> ans;
    void solve(Node * root , vector<int> ref){
        
        if (root==NULL){
            return ;
        }
        ref.push_back(root->data);
        if (root->left == NULL && root->right == NULL){
            ans.push_back(ref);
            return ;
        }
        
        solve(root->left, ref);
        solve(root->right , ref);
        return ; 
    }
    vector<vector<int>> Paths(Node* root) {
        vector<int> ref;
        solve(root , ref);
        return ans ;
    }
};
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
  
    pair<int ,int > solve(Node * root ){
        if (root == nullptr){
            return make_pair(0,0);
        }
        
        pair<int,int> left = solve(root -> left);
        pair<int,int> right = solve(root -> right);
        
        pair<int ,int> ans ;
        ans.first = (root -> data) + left.second + right.second;
        ans.second = max(left.first,left.second) + max(right.first , right.second);
        return ans ;
    }
    int getMaxSum(Node *root) {
        // code here
        pair<int ,int > ans = solve(root);
        if (ans.second > ans.first){
            return ans.second;
        }
        return ans.first ;
    }
};
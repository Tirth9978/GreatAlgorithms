/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans ;
        if (root == NULL){
            return ans ;
        }
        map<int,int> node ; 
        queue<pair<Node * , int>> q;
        
        q.push({root , 0});
        
        while(!q.empty()){
            pair<Node * , int> p = q.front();
            Node * frontNode = p.first ;
            int Hd = p.second ;
            q.pop();
            if (node.find(Hd) == node.end()){
                node[Hd] = frontNode->data;
            }
            
            if (frontNode -> left != NULL){
                q.push({frontNode->left , Hd-1});
            }
            if (frontNode -> right != NULL){
                q.push({frontNode->right , Hd +1});
            }
        }
        
        for (auto x : node){
            ans.push_back(x.second);
        }
        return ans ;
    }
};
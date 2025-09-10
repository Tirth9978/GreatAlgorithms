// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    
    
  public:
  
    int countNode(Node * root){
        if (root == NULL){
            return 0;
        }
        
        return 1 + countNode(root -> left) + countNode(root -> right);
    }
    
    bool isCBT(Node * root , int index , int totalNode){
        if (root == NULL){
            return true;
        }
        
        if (index >= totalNode){
            return 0;
        }
        
        bool left = isCBT(root -> left , (index*2)+1 , totalNode);
        bool right = isCBT(root -> right , (index*2)+2 , totalNode);
        
        return left && right ;
    }
    
    bool isHeap1(Node* root){
        if (root == NULL){
            return 1;
        }
        if (root -> left != NULL && root -> right == NULL ){
            if (root -> left -> data > root -> data){
                return false ;
            }
        }
        if (root -> left == NULL && root -> right != NULL){
            if (root -> right -> data > root -> data){
                return false ;
            }
        }
        
        if (root -> left != NULL && root -> right != NULL){
            if (root -> left -> data > root -> data || root -> right -> data > root -> data){
                return false ;
            }
        }
        
        bool left = isHeap1(root->left);
        bool right = isHeap1(root -> right);

        return left && right;
    }
    
    bool isHeap(Node* tree) {
        int nodeCount = countNode(tree);
        if (isCBT(tree , 0 , nodeCount) && isHeap1(tree)){
            return true;
        }
        return 0;
    }
};
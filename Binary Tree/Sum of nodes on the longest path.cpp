/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
    
    
  public:
  
    void ans(Node * root , int sum,int &mx,int len , int mxLen){
        if (root == NULL){
            // code
            if (len > mxLen){
                mx = max(sum , mx);
                mxLen = max(mxLen,len);
            }
            else if(len == mxLen){
                mx = max(sum,mx);
            }
            
            return ;
        }
        sum += root -> data ;
        ans(root -> left , sum , mx , len + 1 ,mxLen );
        ans(root -> right , sum , mx , len + 1 , mxLen);
        
        return ;
        
    }
    int sumOfLongRootToLeafPath(Node *root) {
        if (root == NULL){
            return 0;
        }
        int mx=0;
        ans(root , 0,mx,0,0);
        return  mx ;
    }
};
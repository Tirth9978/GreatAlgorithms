


// } Driver Code Ends

// User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
  
    void solve(Node * root , int sum,int level ,int & maxSum,int & maxLevel){
        if (root == NULL){
            if (level > maxLevel){
                maxLevel = level;
                maxSum = sum;
            }
            else if (maxLevel == level){
                maxSum = max(maxSum,sum);
            }
            return ;
        }
        
        sum += root -> data ;
        
        solve(root->left,sum , level + 1 ,maxSum,maxLevel);
        solve(root->right,sum , level + 1 ,maxSum,maxLevel);
        return ;
    }
    int sumOfLongRootToLeafPath(Node *root) {
        int sum =0;
        int maxSum =0;
        int level =0;
        int maxLevel = 0;
        solve(root,sum,level,maxSum,maxLevel);
        return maxSum;
    }
};

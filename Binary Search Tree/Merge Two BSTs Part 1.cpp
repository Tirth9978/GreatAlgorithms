/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

void inorder(TreeNode * root , vector<int> & arr){
    if (root == NULL){
        return ;
    }
    inorder(root -> left , arr);
    arr.push_back(root -> data);
    inorder(root -> right , arr);
}

vector<int> doSorting(vector<int> arr1 , vector<int> arr2){
    vector<int> ans(arr1.size() + arr2.size());
    int i =0,j=0,k=0;
    while(i < arr1.size() && j < arr2.size()){
        if (arr1[i] < arr2[j]){
            ans[k] = arr1[i];
            i ++ ;
           
        }
        else {
            ans[k] = arr2[j];
            j ++ ;
          
        }
        k ++ ;
    }

    while(i < arr1.size()){
        ans[k] = arr1[i];
        i ++ ;k++;
    }
    while(j < arr2.size()){
        ans[k] = arr2[j];
        j ++ ;k++;
    }
    return ans ;
}

TreeNode * solve(vector<int> & arr ,int s ,int e){
    if (s > e){
        return NULL ;
    }
    TreeNode * root = new TreeNode(arr[s+(e-s)/2]);
    root -> left = solve(arr , s , (s+(e-s)/2)-1);
    root -> right = solve(arr , (s+(e-s)/2) + 1 , e);
    return root ;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> arr1 ;
    vector<int> arr2;
    inorder(root1 , arr1);
    inorder(root2 , arr2);

    vector<int> ans = doSorting(arr1,arr2);
    vector<int> ref1; 
    
    inorder(solve(ans , 0,ans.size()-1) , ref1);
    return ref1;
}
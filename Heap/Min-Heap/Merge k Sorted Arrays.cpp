class Solution {
  public:
    // Function to merge k sorted arrays.
    class node {
        public :
            int data ;
            int i ; 
            int j ;
        node(int data , int i , int j){
            this-> data = data ;
            this -> i = i;
            this -> j = j;
        }      
    };
    
    class comparator{
        public :
            bool operator()(node * a , node * b) {
                return a -> data > b->data;
            }
    };
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<node* , vector<node*> ,comparator> min_Heap;
        vector<int> ans ;
        
        for (int i=0;i<K;i++){
            int data = arr[i][0];
            int ith = i;
            int jth = 0;
            node* tem = new node(data,ith,jth);
            
            min_Heap.push(tem);
        }
        
        while(min_Heap.size() > 0){
            node * tem = min_Heap.top();
            min_Heap.pop();
            
            int data = tem->data;
            int i = tem->i;
            int j = tem->j;
            
            ans.push_back(data);
            
            if(j < arr[i].size() - 1){
                node * newNode =new node(arr[i][j+1] , i , j + 1);
                min_Heap.push(newNode);
            }
        }
        
        return ans ;
    }
};
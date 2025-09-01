#include<iostream>
#include<queue>
using namespace std ;

class Node {
     public :
          int data ;
          Node * left ;
          Node * right ;

          Node (int data) {
               this -> data = data ;
               this -> left = NULL;
               this-> right = NULL ;
          }
};

Node * insertInBST(Node * & root , int data){
     if (root == NULL){
          root = new Node(data);
          return root;
     }

     if (root -> data >= data){
          root -> left = insertInBST(root -> left , data);
     }
     else {
          root -> right = insertInBST(root -> right , data );
     }
     return root ;
}

void levelOrder(Node * root ) {
     if (root == NULL){
          return ;
     }
     queue<Node * > q;
     q.push(root);
     q.push(NULL);

     while(!q.empty()){
          if (q.front() == NULL){
               cout << endl; 
               q.pop();
               if (!q.empty()){
                    q.push(NULL);
               }
          }

          Node * front = q.front();
          q.pop();
          cout << front->data << " ";
          if (front -> left){
               q.push(front-> left);
          }
          if (front -> right){
               q.push(front->right);
          }

     }
     return ;
}    

int main(){
     int n;
     cin >> n;
     int arr[n];
     for (int i=0;i<n;i++){
          cin >> arr[i];
     }

     Node * root = NULL ;
     for (int i=0;i<n;i++){
          root = insertInBST(root , arr[i]);
     }

     levelOrder(root);
     return 0;
}
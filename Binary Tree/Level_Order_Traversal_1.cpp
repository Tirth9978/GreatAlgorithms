#include<iostream>
#include<queue>
using namespace std ;


// Node Calss 
class Node{
     public : 
          int data ;
          Node * left ;
          Node * right ;
     Node (int data) {
          this-> data = data ;
          this->left = NULL ;
          this->right = NULL ;
     }
};   

Node * builtTree(Node * root){
     cout << "Enter the Number : " ;
     int data ;
     cin >> data ;
     if (data == -1){
          return NULL ;
     }

     root = new Node(data); 

     cout << "Data is Going to Inserting in the Left of " << data << endl;;
     root -> left = builtTree(root->left);

     cout << "Data is Going to inderting to the right of " << data << endl ;
     root->right = builtTree(root->right);

     return root ;
}

void levelOrderTraversal(Node * root){
     if (root == NULL){
          return ;
     }

     queue<Node*> q;
     q.push(root);
     q.push(NULL);

     while(!q.empty()){
          if (q.front() == NULL){
               cout << endl; 
               q.pop();
               if (!q.empty()){
                    q.push(NULL);
               }
               
               continue;
          }
          if (q.front() -> left != NULL){
               q.push(q.front()->left);
          }
          if (q.front() -> right != NULL){
               q.push(q.front()->right);
          }

          cout << q.front() -> data << " ";
          q.pop();
     }

     return ;
}

int main(){
     Node * root = NULL ;
     root = builtTree(root);
     levelOrderTraversal(root);
     return 0;
}
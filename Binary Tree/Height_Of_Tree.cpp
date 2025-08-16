#include<iostream>
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

int Height(Node * head ){
     if (head == NULL){
          return 0;
     }

     int left = Height(head -> left);
     int right = Height(head -> right);

     return max(left,right)+1;
}

int main(){
     Node * root = NULL ;
     root = builtTree(root);
     cout << Height(root);
     return 0;
}
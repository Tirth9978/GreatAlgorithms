#include<iostream>
using namespace std ;

class Node{
     public :
          int data ;
          Node * left ;
          Node * right ;

          Node(int data ) {
               this->data = data ;
               this-> left = NULL;
               this->right = NULL;
          }    
};

void inOrder(Node * root){
     if (root == NULL)return ;

     inOrder(root->left);
     cout << root->data << " ";
     inOrder(root->right);
     
     return ;
}

int main(){
     return 0;
}
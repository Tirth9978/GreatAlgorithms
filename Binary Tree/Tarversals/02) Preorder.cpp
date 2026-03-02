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

void preOrder(Node * root){
     if (root == NULL)return ;

     
     cout << root->data << " ";
     preOrder(root->left);
     preOrder(root->right);
     
     return ;
}

int main(){
     return 0;
}
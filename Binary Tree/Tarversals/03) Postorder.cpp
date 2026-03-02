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

void postOrder(Node * root){
     if (root == NULL)return ;

     postOrder(root->left);
     postOrder(root->right);
     cout << root->data << " ";
          
     return ;
}

int main(){
     return 0;
}
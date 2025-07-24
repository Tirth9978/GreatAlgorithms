#include<iostream>
using namespace std ;

class Node {
     public : 
          int data ;
          Node * next ;

     Node(int data ){
          this-> data;
          this->next = NULL;
     }
};

int main(){
     Node * head = new Node(10);
     
     return 0;
}
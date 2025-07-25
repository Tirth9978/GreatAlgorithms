#include <iostream>
using namespace std;

class Node {
public:
     int data;
     Node *next;

     Node(int data){
          this->data = data;
          this->next = NULL;
     }
};

Node * newNode(Node * head){
     if (head == NULL){
          return NULL ;
     }

     Node * temp = head ;
     head = head -> next;

     delete temp ;
     return head ;
}

int main(){
     
     return 0;
}
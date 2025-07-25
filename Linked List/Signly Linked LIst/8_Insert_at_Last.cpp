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

void printList(Node *head) {
     while (head != NULL) {
          cout << head->data << " ";
          head = head->next;
     }
     cout << endl;
     return;
}

Node * insertAtLast(Node * head , int num){
     if (head == NULL){
          head = new Node(num);
          return head;
     }    
     Node * temp = head;
     while(head -> next != NULL){
          head = head -> next ;
     }
     Node * ref = new Node(num);
     head -> next = ref ;
     return temp ;
}    

int main(){
     int n;
     cin >> n;

     int num;
     cin >> num;
     Node *temp = new Node(num);
     Node *head = temp;
     n--;
     while (n--){
          cin >> num;

          Node *ref = new Node(num);
          temp->next = ref;
          temp = ref;
     }
     
     int num1 ;
     cout << "Enter the Number : " ;
     cin >> num1; 
     Node * ans = insertAtLast(head,num1);
     printList(ans);
     return 0;
}
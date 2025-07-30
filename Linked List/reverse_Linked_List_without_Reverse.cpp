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

int addingOne(Node * head ){
     if (head == NULL){
          return 1;
     }

     int crr = addingOne(head-> next);

     head->data = (head -> data) + crr ;
     if (head->data < 10){
          return 0;
     }
     head -> data = 0 ;
     return 1 ;
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
     
     int crr = addingOne(head);
     if (crr == 1){
          Node * ref = new Node(crr);
          ref-> next = head;
          head = ref;
     }
     printList(head);
     return 0;
}
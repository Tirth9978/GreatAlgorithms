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

Node * insertAtHead(Node * head , int num){
     if (head == NULL){
          head = new Node(num);
          return head;
     }    
     Node * ref = new Node(num);
     ref-> next = head;
     return ref;
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
     Node * ans = insertAtHead(head,num1);
     printList(ans);
     return 0;
}
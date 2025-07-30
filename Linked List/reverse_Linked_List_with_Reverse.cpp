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

Node * reverse(Node * head , Node * prev , Node * next ){
     if (next == NULL){
          head -> next = prev;
          return head;
     }

     head -> next = prev ;
     
     Node * newNode = reverse(next , head, next -> next );
     return newNode;
}

Node * addingOne(Node * head){
     int crr = 1;
     Node * temp = head ;
     while(head != NULL){
          int sum = (head -> data) + crr ;
          if (sum <= 9){
               crr = 0;
          }
          if (sum > 9){
               crr = sum / 10 ;
               sum = sum % 10 ;
          }
          head -> data = sum;
          
          if (crr == 0){

          }

          

          if (head -> next == NULL && crr == 1){
               Node * ref = new Node(1);
               head -> next = ref;
               break;
          }
          head = head -> next ;
     }

     return temp;
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
     Node * ans = reverse(head,NULL , head-> next);
     ans = addingOne(ans);
     ans = reverse(ans,NULL , ans-> next);
     
     printList(ans);
     return 0;
}
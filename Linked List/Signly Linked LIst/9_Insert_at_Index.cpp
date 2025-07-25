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

Node * insertAtIndex(Node * head ,int index , int num){
     if (head == NULL){
          return new Node(num);
     }
     int i =0;
     Node * temp = head ;
     while( i != index -1 ){
          i++;
          head = head -> next ;
     }
     
     Node * ref = new Node(num);

     ref -> next = head -> next ;
     head-> next = ref ;
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
     
     int num1 ;
     cout << "Enter the Number : ";
     cin >> num1 ;
     int index ;
     cout << "Enter the Index : " ;
     cin >> index ;
     
     Node * ans = insertAtIndex(head , index, num1);
     printList(ans);
     return 0;
}
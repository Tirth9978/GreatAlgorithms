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

void removeNode(Node * head , int index){
     if (head == NULL ){ 
          return ;
     }
     if (head->next == NULL ){
          delete head;
          return ;
     }
     int i =0;
     while(i != index -1 ){
          head = head -> next ;
          i++;
     }
     Node * temp = head -> next ;
     head -> next = head-> next -> next ;
     delete temp ;
     return ;
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
     
     int index ;
     cout << "Enter the Index : " ;
     cin >> index ;

     removeNode(head ,index);
     printList(head);
     return 0;
}
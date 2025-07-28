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
     printList(ans);
     
     return 0;
}
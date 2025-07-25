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

int lenght(Node * head){
     int count = 0;
     while(head != NULL){
          count ++ ;
          head = head -> next ;
     }
     return count ;
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
     
     cout << "Length : " << lenght(head) << endl; 
     return 0;
}
#include <iostream>
using namespace std;

class Node
{
public:
     int data;
     Node *next;
     Node *prev;

     Node(int data)
     {
          this->data = data;
          this->next = NULL;
          this->prev = NULL;
     }
};

void printLinkedList(Node *head)
{
     while (head != NULL)
     {
          cout << head->data << " ";
          head = head->next;
     }
     cout << endl;
     return;
}

Node *arrayToLinkedList(int arr[], int n)
{
     Node *temp = new Node(arr[0]);
     Node *head = temp;

     for (int i = 1; i < n; i++)
     {
          Node *ref = new Node(arr[i]);
          ref->prev = temp;
          temp->next = ref;

          temp = temp->next;
     }
     return head;
}

Node * insertAtEnd(Node * head , int num){
     if (head == NULL){
          return new Node(num);
     }
     Node * temp = head ;
     while(head -> next != NULL){
          head = head -> next ;
     }

     Node * ref = new Node(num) ;
     head -> next = ref ;
     head -> next -> prev = head ;

     return temp;
}

int main()
{
     int n;
     cin >> n;
     int arr[n];
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i];
     }
     Node *ans = arrayToLinkedList(arr, n);
     int num ;
     cout << "Enter the Index : ";
     cin >> num ; 
     ans = insertAtEnd(ans,num);
     printLinkedList(ans);
     return 0;
}
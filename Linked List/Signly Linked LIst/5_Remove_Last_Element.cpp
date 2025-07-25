#include <iostream>
using namespace std;

class Node
{
public:
     int data;
     Node *next;

     Node(int data)
     {
          this->data = data;
          this->next = NULL;
     }

     ~Node()
     {
          
     }
};

void printList(Node *head)
{
     while (head != NULL)
     {
          cout << head->data << " ";
          head = head->next;
     }
     cout << endl;
     return;
}

void removeLast(Node *head)
{
     if (head == NULL)
     {
          return;
     }
     if (head->next == NULL)
     {
          delete head;
          return;
     }

     while (head->next->next != NULL)
     {
          head = head->next;
     }
     delete head->next;
     head->next = NULL;
     return;
}

int main()
{
     int n;
     cin >> n;

     int num;
     cin >> num;
     Node *temp = new Node(num);
     Node *head = temp;
     n--;
     while (n--)
     {
          cin >> num;

          Node *ref = new Node(num);
          temp->next = ref;
          temp = ref;
     }

     removeLast(head);
     printList(head);
     return 0;
}
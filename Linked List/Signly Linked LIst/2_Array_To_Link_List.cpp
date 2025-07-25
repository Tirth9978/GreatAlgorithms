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
};

void printList(Node *head)
{
     while (head != NULL)
     {
          cout << head->data << " ";
          head = head->next;
     }
     cout << endl;
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
     // printList(head);
     while (head != NULL)
     {
          cout << head->data << " ";
          head = head->next;
     }
     return 0;
}
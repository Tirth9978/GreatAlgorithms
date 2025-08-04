#include<iostream>
#include<vector>
using namespace std ;

class Node {
     public : 
          int data ;
          Node * next ;
          Node * prev;

     Node(int data ){
          this-> data = data ;
          this -> next = NULL ;
          this->prev = NULL ;
     }
};

void printLinkedList(Node * head) {
     while(head != NULL){
          cout << head -> data << " ";
          head = head -> next ;
     }
     cout << endl;
     return ;
}

Node * arrayToLinkedList(int arr[],int n){
     Node * temp = new Node(arr[0]);
     Node * head = temp ;

     for (int i=1;i<n;i++){
          Node * ref = new Node(arr[i]);
          ref->prev = temp;
          temp->next = ref;
          
          temp = temp -> next ;
     }
     return head ;
}

Node * getTail(Node * head){
     if (head == NULL){
          return head;
     }

     while(head -> next != NULL){
          head= head-> next;
     }

     return head ;
}

void pairs(Node * head,vector<pair<int,int>> & ans ,int sum){
     if (head == NULL){
          return ;
     }

     Node * start = head;
     Node * end = getTail(head);

     while(start != end){
          if ((start-> data)+ (end -> data) == sum){
               pair<int ,int > p = make_pair(start->data , end->data);
               ans.push_back(p);
               end = end -> prev;
          }
          else if ((start-> data)+ (end -> data) > sum){
               end = end->prev;
          }
          else {
               start = start -> next ;
          }
     }
     return ;
}

int main(){
     int n;
     cin >> n;
     int arr[n];
     for (int i=0;i<n;i++){
          cin >> arr[i];
     }
     Node * ans = arrayToLinkedList(arr,n);
     vector<pair<int,int>> p ;
     int sum =0 ;
     cout << "Enter the Sum : ";
     cin >> sum ;
     pairs(ans,p,sum);

     for (auto x : p){
          cout << x.first << " " << x.second << endl;
     }
     
     return 0;
}
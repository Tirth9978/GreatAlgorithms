/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

bool find(Node * head){
    Node * slow = head ;
    Node * fast = head -> next ;

    while(slow != NULL && fast != NULL){
        fast = fast -> next ;
        if (fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next ;
        if (fast == slow){
            return 1;
        }
    }
    return 0;
}

int lengthOfLoop(Node *head) {
    if (!find(head)){
        return 0;
    }

    Node * slow = head ;
    Node * fast = head -> next ;
    while(slow != fast){
        fast = fast -> next;
        fast = fast -> next;
        slow = slow -> next; 
    }

    int count = 0;
    fast = fast -> next;
    while(fast != slow){
        fast = fast -> next;
        count ++;
    }
    return count+1;
}

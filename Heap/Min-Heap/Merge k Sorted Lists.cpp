/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class compator{
    public :

    bool operator()(ListNode * a , ListNode * b)
    {
        return a -> val > b -> val;
    }
};  

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode * , vector<ListNode * > , compator> min_Heap;

        for (int i=0;i<lists.size();i++){
            if (lists[i] != NULL){
                min_Heap.push(lists[i]);
            }
        }

        ListNode * head =NULL ; 
        ListNode * tail =NULL;

        while(min_Heap.size() > 0){
            ListNode * temp = min_Heap.top();
            min_Heap.pop();

            if (temp->next != NULL){
                min_Heap.push(temp->next);
            }
            
            if (head == NULL){
                head = temp ; 
                tail = temp;
            }
            else {
                tail -> next = temp ;
                tail = temp ;
            }
        }

        return head;
    }
};
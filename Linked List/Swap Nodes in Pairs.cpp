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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head -> next == NULL){
            return head ;
        }

        ListNode * a = head  ;
        ListNode * b = head -> next ;

        a -> next = b -> next ;
        b -> next= a ;

        a-> next  = swapPairs(a->next);
        
        return b ;

    }   

};
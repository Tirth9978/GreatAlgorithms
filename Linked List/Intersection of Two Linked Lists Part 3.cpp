/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * l1 = headA;
        ListNode * l2 = headB;
        int count =0;
        while(count != 2){
            if (l1 == NULL){
                count ++ ;
                l1 = headB;
                continue;
            }
            if (l2 == NULL){
                count ++ ;
                l2 = headA;
                continue;
            }
            l1 = l1 -> next ;
            l2 = l2 -> next ;
        }   

        while(l1 != l2){
            l1 = l1 -> next ;
            l2 = l2 -> next ;

        }
        return l1;
    }
};
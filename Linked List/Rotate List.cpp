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

    void oneRotation(ListNode* head,int n){
        if (head == NULL){
            return ;
        }

        int num = head -> val;
        head -> val = n ;
        oneRotation(head -> next , num);
        return ;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head -> next == NULL){
            return head;
        }
        
        ListNode * temp = head ;
        int count = 0;
        while(head != NULL){
            count ++ ;
            head = head -> next;
        }
        head = temp;
        k = k % count ;
        while(k--){
            int lastVal ;
            
            while(head != NULL){
                if (head -> next == NULL){
                    lastVal = head -> val ;
                }
                head  = head -> next ;
            }
            head = temp;
            oneRotation(head -> next , head -> val);
            head -> val = lastVal ;
        }
        return temp;
    }
};
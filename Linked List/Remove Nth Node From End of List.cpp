// This is the LeetCode Problem 
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

    int Lenght(ListNode * head){
        int count =0;
        while(head != NULL){
            count ++ ;
            head = head -> next ;
        }

        return count ;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head -> next == NULL){
            return NULL ;
        }
        int length = Lenght(head);
        int index = length - n;
        if (index == 0){
            return head -> next ;
        }
        int i = 0;
        ListNode * ans = head ;
        while(i != index -1){
            head = head -> next ;
            i ++ ;
        }

        ListNode * temp = head -> next ;
        head -> next = head -> next -> next ;
        delete temp;
        return ans ;
    }
};
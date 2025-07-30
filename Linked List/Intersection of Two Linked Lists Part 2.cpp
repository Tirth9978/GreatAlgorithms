// This is the Leetcode Problem 


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

    int length(ListNode * head){
        int count =0;
        while(head != NULL){
            count ++ ;
            head = head-> next;
        }

        return count ;
    }

    ListNode * findAns(ListNode * smaller , ListNode * bigger , int d){
        while(d){
            bigger = bigger->next;
            d--;
        }

        while(smaller != bigger){
            smaller = smaller -> next;
            bigger = bigger -> next ;
        }
        return smaller ;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1 = length(headA);
        int count2 = length(headB);
        
        if (count2 > count1){
            return findAns(headA , headB , count2 - count1);
        }
        return findAns(headB , headA , count1 - count2);
    }
};
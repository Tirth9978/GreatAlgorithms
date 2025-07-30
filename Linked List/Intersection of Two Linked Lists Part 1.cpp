// This is the Problem of the Leetcode 
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
        map<ListNode * ,int> mp;
        while(headA != NULL){
            mp[headA] ++ ;
            headA = headA -> next;
        }
        while(headB != NULL){
            mp[headB] ++ ;
            headB = headB -> next;
        }

        for (auto x : mp){
            if (x.second > 1){
                return x.first;
            }
        }
        return NULL;
    }
};
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
    bool isPalindrome(ListNode* head) {
        stack<int> st ;
        ListNode * temp = head ;
        while(head != NULL){
            st.push(head -> val);
            head = head -> next ;
        }

        while(!st.empty()){
            if (st.top() != temp-> val){
                return 0;
            }
            st.pop();
            temp = temp -> next ;
        }
        return 1;
    }
};
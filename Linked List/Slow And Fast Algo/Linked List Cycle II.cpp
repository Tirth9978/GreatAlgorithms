// This is th Problem of the LInked List

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
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
        if (fast == NULL || slow == NULL) {
                return NULL;
            }
        while (slow != fast) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
            }
            slow = slow->next;

            if (fast == NULL || slow == NULL) {
                return NULL;
            }
        }

        slow = head;

        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
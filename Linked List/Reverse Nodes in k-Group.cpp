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
    bool check(ListNode* head, int k) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        if (count >= k) {
            return 1;
        }
        return 0;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        if (!check(head, k)) {
            return head;
        }
        ListNode* temp = head;

        ListNode* next = head->next;
        ListNode* prev = NULL;

        for (int i = 0; i < k; i++) {
            head->next = prev;
            prev = head;
            head = next;
            
            if (next != NULL) {
                next = next->next;
            }
        }
        // cout << prev -> val;
        temp->next = reverseKGroup(head, k);
        return prev;
    }
};
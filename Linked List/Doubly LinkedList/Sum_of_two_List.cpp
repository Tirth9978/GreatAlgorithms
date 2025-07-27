// This is the Probelm of the Linked List


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
class Solution
{
public:
     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
     {
          int carr = 0;
          int sum = (l1->val) + (l2->val);

          if (sum > 9)
          {
               carr = sum / 10;
               sum = sum % 10;
          }
          l1 = l1->next;
          l2 = l2->next;
          ListNode *temp = new ListNode(sum);
          ListNode *ans = temp;

          while (l1 != NULL && l2 != NULL)
          {
               sum = (l1->val) + (l2->val) + carr;
               if (carr > 0)
               {
                    carr--;
               }
               if (sum > 9)
               {
                    carr = sum / 10;
                    sum = sum % 10;
               }

               ListNode *ref = new ListNode(sum);
               temp->next = ref;
               temp = ref;
               l1 = l1->next;
               l2 = l2->next;
          }

          while (l1 != NULL)
          {
               sum = (l1->val) + carr;
               if (carr > 0)
               {
                    carr--;
               }
               if (sum > 9)
               {
                    carr = sum / 10;
                    sum = sum % 10;
               }
               ListNode *ref = new ListNode(sum);
               temp->next = ref;
               temp = ref;
               l1 = l1->next;
          }

          while (l2 != NULL)
          {
               sum = (l2->val) + carr;
               if (carr > 0)
               {
                    carr--;
               }
               if (sum > 9)
               {
                    carr = sum / 10;
                    sum = sum % 10;
               }
               ListNode *ref = new ListNode(sum);
               temp->next = ref;
               temp = ref;
               l2 = l2->next;
          }
          if (carr > 0)
          {
               ListNode *ref = new ListNode(carr);
               temp->next = ref;
               temp = ref;
          }
          return ans;
     }
};
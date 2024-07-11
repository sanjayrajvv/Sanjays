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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;

        while (curr) {
            next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;
        ListNode *mid = reverseList(slow);
        prev->next = mid;

        int maxTwin = 0;
        ListNode *first = head;
        while (mid) {
            if (first->val + mid->val > maxTwin) {
                maxTwin = first->val + mid->val;
            }

            first = first->next;
            mid = mid->next;
        }

        return maxTwin;
    }
};
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode *dummy = new ListNode(0, head);

        ListNode *prev = dummy;

        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        ListNode *c = prev->next;
        ListNode *p = NULL;
        ListNode *next = NULL;
        for (int i = 0; i <= right - left; i++) {
            next = c->next;
            c->next = p;
            p = c;
            c = next;
        }

        prev->next->next = c;
        prev->next = p;

        return dummy->next;
    }
};
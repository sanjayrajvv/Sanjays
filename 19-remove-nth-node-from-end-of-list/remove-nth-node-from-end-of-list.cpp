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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1, head);

        ListNode *l = dummy;
        ListNode *r = head;

        int k = n;
        while (r && k > 0) {
            r = r->next;
            k--;
        }

        while (r) {
            l = l->next;
            r = r->next;
        }

        if (l->next) {
            l->next = l->next->next;
        }

        return dummy->next;
    }
};
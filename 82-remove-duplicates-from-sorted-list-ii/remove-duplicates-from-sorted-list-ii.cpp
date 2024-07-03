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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(1e9, head);

        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr && curr->next) {
            while (curr->next && curr->next->val != curr->val) {
                prev = curr;
                curr = curr->next;
            }

            int flag = 0;
            while (curr->next && curr->next->val == curr->val) {
                curr = curr->next;
                flag = 1;
            }

            if (flag) {
                curr = curr->next;
            prev->next = curr;
            }
        }

        return dummy->next;
    }
};

//steps
//1) Find the prev node of repeating numbers
//2) connect prev pointer to all elements after the current repaeting element
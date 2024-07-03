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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessList = new ListNode(1e9);
        ListNode *greatList = new ListNode(1e9);

        ListNode *less = lessList;
        ListNode *great = greatList;

        while (head) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                great->next = head;
                great = great->next;
            }

            head = head->next;
        }

        great->next = NULL;
        less->next = greatList->next;

        return lessList->next;
    }
};
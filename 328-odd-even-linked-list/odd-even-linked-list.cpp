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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;

        ListNode *dummyOdd = new ListNode(-1);
        ListNode *dummyEven = new ListNode(-1);

        ListNode *lastOdd = dummyOdd;
        ListNode *lastEven = dummyEven;

        ListNode *odd = head;
        ListNode *even = head->next;

        while (odd && even) {
            lastOdd->next = odd;
            lastEven->next = even;

            lastOdd = lastOdd->next;
            lastEven = lastEven->next;

            odd = odd->next ? odd->next->next : nullptr;
            even = even->next ? even->next->next : nullptr;
        }

        if (odd) {
            lastOdd->next = odd;
            lastOdd = lastOdd->next;
        }

        // Terminate the even list
        lastEven->next = nullptr;
        
        // Connect the end of the odd list to the beginning of the even list
        lastOdd->next = dummyEven->next;

        return dummyOdd->next;

    }
};
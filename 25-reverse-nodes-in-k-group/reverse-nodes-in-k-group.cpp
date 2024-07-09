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
    void reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = head;

        while (curr) {
            next = next->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }

    ListNode *findKth(ListNode *temp, int k) {
        for (int i = 1; i < k && temp; i++) {
            temp = temp->next;
        }

        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *Kth = head;
        ListNode *prevNode = NULL;

        while (temp) {
            Kth = findKth(temp, k);

            if (!Kth) {
                if (prevNode) prevNode->next = temp;
                break;
            }

            ListNode *nextNode = Kth->next;
            Kth->next = NULL;

            reverseList(temp);

            if (temp == head) {
                head = Kth;
            } else {
                prevNode->next = Kth;
            }

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};
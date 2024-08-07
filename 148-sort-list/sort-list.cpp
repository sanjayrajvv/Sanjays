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
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(1e9);
        ListNode* tail = dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = l1 ? l1 : l2;
        return dummy->next;
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* mid = getMid(head);
        ListNode* right = mid->next;
        mid->next = nullptr; // Split the list into two halves
        
        ListNode* leftSorted = mergeSort(head);
        ListNode* rightSorted = mergeSort(right);
        
        return merge(leftSorted, rightSorted);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};

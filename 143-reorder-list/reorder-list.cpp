class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* h1 = head;
        ListNode* h2 = reverseList(slow->next);
        slow->next = nullptr;

        while (h1 != nullptr && h2 != nullptr) {
            ListNode* temp1 = h1->next;
            ListNode* temp2 = h2->next;

            h1->next = h2;
            h2->next = temp1;

            h1 = temp1;
            h2 = temp2;
        }
    }

private:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head;

        while (curr != nullptr) {
            next = next->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};
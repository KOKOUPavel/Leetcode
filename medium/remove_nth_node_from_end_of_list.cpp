
class Solution {
public:
    int findSize(ListNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return NULL;

        int size = findSize(head);

        if (size == 1)
            return NULL;

        if (n == size)
            return head->next;

        ListNode* temp = head;
        for (int i = 1; i < size - n; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};
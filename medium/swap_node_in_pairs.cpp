class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* prev = temp;

        while(prev->next != nullptr && prev->next->next != nullptr){
            ListNode* a = prev->next;
            ListNode* b = a->next;
            a->next = b->next;
            b->next = a;
            prev->next = b;

            prev = a;
        }

        return temp->next;
    }
};

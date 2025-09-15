// Last updated: 9/16/2025, 12:09:58 AM
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        
        // 1. Find length and tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        // 2. Adjust k
        k = k % length;
        if (k == 0) return head;
        
        // 3. Find new tail: (length - k - 1) moves
        ListNode* newTail = head;
        for (int i = 1; i < length - k; i++) {
            newTail = newTail->next;
        }
        
        // 4. Set new head and break
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        
        return newHead;
    }
};

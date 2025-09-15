// Last updated: 9/16/2025, 12:06:09 AM
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* firstK = head;
        
        // Step 1: Get kth node from start
        for (int i = 1; i < k; i++) {
            firstK = firstK->next;
        }

        // Step 2: Use fast and slow pointers to find kth from end
        ListNode* fast = head;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }

        ListNode* secondK = head;
        while (fast != nullptr) {
            fast = fast->next;
            secondK = secondK->next;
        }

        // Step 3: Swap values
        swap(firstK->val, secondK->val);

        return head;
    }
};

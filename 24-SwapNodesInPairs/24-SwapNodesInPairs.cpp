// Last updated: 9/16/2025, 12:10:40 AM
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
    ListNode* swapPairs(ListNode* head) {
        // If list has 0 or 1 nodes, no swap needed
        if (!head || !head->next) return head;

        // Update the head to the second node (it becomes the new head after first swap)
        ListNode* newHead = head->next;

        // Pointers to keep track of previous and current nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* nextNode = curr->next;
            ListNode* nextPair = curr->next->next;

            // Perform the swap
            nextNode->next = curr;
            curr->next = nextPair;

            if (prev) {
                prev->next = nextNode;
            }

            // Move to the next pair
            prev = curr;
            curr = nextPair;
        }

        return newHead;
    }
};

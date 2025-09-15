// Last updated: 9/16/2025, 12:10:49 AM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* slow=head;
        ListNode* fast=head;

        for(int i=0; i<n ; i++){
            slow=slow->next;
        }

        if (slow == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }       

        while(slow!=nullptr && slow->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        fast->next=fast->next->next;
        return head;
    }
};
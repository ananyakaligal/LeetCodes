// Last updated: 9/16/2025, 12:01:42 AM
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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || head->next==nullptr) return nullptr;

        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pre=nullptr;

        while(fast!=nullptr && fast->next!=nullptr){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=slow->next;
        delete slow;
        return head;
    }
};
// Last updated: 9/16/2025, 12:07:24 AM
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
    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) return true;

        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        //reverse
        ListNode* dummy=nullptr;
        ListNode* curr=slow;

        while(curr){
            ListNode* temp=curr->next;

            curr->next=dummy;
            dummy=curr;
            curr=temp;
        }

        //compare
        fast=head;
        slow=dummy;
        while(slow && fast){
            if(slow->val!=fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
};
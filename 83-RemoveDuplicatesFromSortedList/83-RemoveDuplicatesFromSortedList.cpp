// Last updated: 9/16/2025, 12:09:29 AM
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || head->next==nullptr) return head;
        ListNode* curr=head;

        while (curr->next != nullptr) {
            if(curr->val==curr->next->val){
                curr->next=curr->next->next;
            }else{
                curr=curr->next;
            }
        }
        return head;
    }
};
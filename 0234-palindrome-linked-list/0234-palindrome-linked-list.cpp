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
        if(!head) return true;
        ListNode *fast=head, *slow=head,*back=NULL;

        while(fast && fast->next){
            fast = fast->next->next;

            ListNode * nxt = slow->next;
            slow->next = back;
            back = slow;

            slow = nxt;
        }
        ListNode *p=slow,*q;
        if(!fast){
            q=back;
        }
        else{
            p=slow->next;
            q=back;
        }

        while(p){
            if(p->val!=q->val) return false;
            p=p->next;
            q=q->next;
        }

        return true;
    }
};
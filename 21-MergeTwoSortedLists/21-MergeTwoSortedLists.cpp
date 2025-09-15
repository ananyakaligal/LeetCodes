// Last updated: 9/16/2025, 12:10:44 AM
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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;

        while(a && b){
            if(a->val<b->val){
                curr->next=a;
                a=a->next;
            }else{
                curr->next=b;
                b=b->next;
            }
            curr=curr->next;
        }

    if (a) curr->next = a;
    else curr->next = b;

    return dummy->next;

    }
};
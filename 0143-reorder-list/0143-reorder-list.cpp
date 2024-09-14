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
    ListNode* reverse(ListNode* head){
        if(head==NULL||head->next==NULL)
        return head;

        ListNode* prev=NULL;
        ListNode* next_node=head;
        ListNode* currn=head;
        while(currn!=NULL){
            next_node=next_node->next;
            currn->next=prev;
            prev=currn;
            currn=next_node;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       ListNode* second_half = reverse(slow->next);
    slow->next = NULL;

    //merge the two halves
    ListNode* first_half = head;
    ListNode* next1 = NULL;
    ListNode* next2 = NULL;

    while (second_half != NULL) {
        next1 = first_half->next;
        next2 = second_half->next;

        first_half->next = second_half;
        second_half->next = next1;

        first_half = next1;
        second_half = next2;
    }

       
    }
};
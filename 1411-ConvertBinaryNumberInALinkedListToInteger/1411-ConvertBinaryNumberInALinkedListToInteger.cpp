// Last updated: 9/16/2025, 12:03:23 AM
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
    int getDecimalValue(ListNode* head) {
        ListNode* curr=head;
        int sum=0;

        while(curr!=nullptr){
            sum=(sum<<1)|curr->val;
            curr=curr->next;
        }
        return sum;
    }
};

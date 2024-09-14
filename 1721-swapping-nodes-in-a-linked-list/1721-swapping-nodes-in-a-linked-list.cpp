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

        ListNode *addr1, *addr2;
        int len = 0;
        ListNode *tmp = head;
        while(tmp != NULL) {
            tmp = tmp->next;
            len++;
        }

        tmp = head;
        int ind = 0;
        while(tmp != NULL) {
            if (ind + 1 == k) {
                addr1 = tmp;
            } 
            if (ind + 1 == len - k + 1) {
                addr2 = tmp;
            }
            tmp = tmp->next;
            ind++;
        }

        int tmpData = addr1->val;
        addr1->val = addr2->val;
        addr2->val = tmpData;
        return head;
    }
};
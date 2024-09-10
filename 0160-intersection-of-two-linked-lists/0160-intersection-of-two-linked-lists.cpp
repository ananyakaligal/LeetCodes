/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* head1 = headA;
        ListNode* head2 = headB;
        int m = 0;
        int n = 0;

        while (head1 != nullptr) {
            m++;
            head1 = head1->next;
        }

        while (head2 != nullptr) {
            n++;
            head2 = head2->next;
        }

        int t = abs(m - n);

        if (m < n) {
            while (t != 0) {
                headB = headB->next;
                t--;
            }
        } else {
            while (t != 0) {
                headA = headA->next;
                t--;
            }
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }    
};

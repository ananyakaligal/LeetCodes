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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* aNode;
        ListNode* bNode;
        ListNode* current1 = list1;
        ListNode* tail1 = list1;

        for(int i=0; i<a-1; i++){
            if(current1 != nullptr){
                current1 = current1->next;
            }
        }

        aNode = current1;

        for(int i=0; i<b+1; i++){
            if(tail1 != nullptr){
                tail1 = tail1-> next;
            }
        }

        bNode = tail1;

        aNode->next = list2;
        
        ListNode* tail2 = list2;

        while(tail2->next != nullptr){
            tail2 = tail2->next;
        }

        tail2->next = bNode;

        return list1;

    }
};
auto speedUP = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;

        ListNode* curr = head;
        while(curr != nullptr){
            
            while(!stk.empty() && stk.top()->val < curr->val){
                stk.pop();
            }

            stk.push(curr);
            curr = curr->next;
        }

        ListNode* temp = nullptr;
        while(!stk.empty()){
            curr = stk.top();
            curr->next = temp;
            temp = curr;
            stk.pop();
        }

        return curr;;
        
    }
};
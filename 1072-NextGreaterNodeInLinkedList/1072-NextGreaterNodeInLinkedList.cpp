// Last updated: 9/16/2025, 12:04:04 AM
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        // Convert linked list to array
        while (head) {
            values.push_back(head->val);
            head = head->next;
        }
        
        int n = values.size();
        vector<int> result(n, 0);
        stack<int> st; // will store indices
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && values[i] > values[st.top()]) {
                result[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
        }
        
        return result;
    }
};

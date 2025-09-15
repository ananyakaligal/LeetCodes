// Last updated: 9/16/2025, 12:03:29 AM
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; // to hold indices of '('
        unordered_set<int> removeIndices; // indices to remove
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    // Unmatched ')'
                    removeIndices.insert(i);
                }
            }
        }
        
        // All remaining '(' indices in stack are unmatched
        while (!st.empty()) {
            removeIndices.insert(st.top());
            st.pop();
        }
        
        // Build the result skipping indices in removeIndices
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (removeIndices.find(i) == removeIndices.end()) {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};

// Last updated: 9/16/2025, 12:10:31 AM
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);  // base index before start
        
        int maxLength = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);  // new base index
                } else {
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }
        
        return maxLength;
    }
};

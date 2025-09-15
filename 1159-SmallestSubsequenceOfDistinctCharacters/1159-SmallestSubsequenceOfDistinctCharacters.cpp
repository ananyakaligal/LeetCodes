// Last updated: 9/16/2025, 12:03:55 AM
class Solution {
public:
    string smallestSubsequence(string s) {
                vector<int> last_index(26, -1);
        vector<bool> seen(26, false);
        
        // Store the last occurrence of every character
        for (int i = 0; i < s.length(); ++i) {
            last_index[s[i] - 'a'] = i;
        }

        stack<char> st;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            // If character is already in stack, skip it
            if (seen[c - 'a']) continue;

            // While current char is smaller than stack top and the top will appear again later
            while (!st.empty() && c < st.top() && last_index[st.top() - 'a'] > i) {
                seen[st.top() - 'a'] = false; // mark as not seen
                st.pop();
            }

            st.push(c);
            seen[c - 'a'] = true;
        }

        // Build result from stack
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
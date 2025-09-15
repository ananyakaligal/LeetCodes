// Last updated: 9/16/2025, 12:06:44 AM
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char it : num) {
            while (!st.empty() && k > 0 && st.top() > it) {
                st.pop();
                k--;
            }
            st.push(it);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') i++;
        result = result.substr(i);

        return result.empty() ? "0" : result;
    }
};

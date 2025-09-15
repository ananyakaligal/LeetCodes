// Last updated: 9/16/2025, 12:05:20 AM
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;                 // Stack stores indices of temperatures
        vector<int> nge(temperatures.size(), 0);  // Vector to store result

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            // Pop all temperatures from the stack that are less than or equal to the current
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack is not empty, the next greater temperature is at the top of the stack
            if (!st.empty()) {
                nge[i] = st.top() - i;  // Store the difference in indices (days to wait)
            }

            // Push the current temperature index onto the stack
            st.push(i);
        }
        return nge;
    }
};

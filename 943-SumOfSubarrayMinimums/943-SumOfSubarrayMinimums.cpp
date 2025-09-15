// Last updated: 9/16/2025, 12:04:34 AM
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Compute left counts
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                left[i] = i + 1;  // can extend to start
            } else {
                left[i] = i - st.top();
            }
            st.push(i);
        }

        // Clear stack for right pass
        while (!st.empty()) st.pop();

        // Compute right counts
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                right[i] = n - i;  // can extend to end
            } else {
                right[i] = st.top() - i;
            }
            st.push(i);
        }

        // Final sum
        long res = 0;
        long MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            res = (res + (long)arr[i] * left[i] * right[i]) % MOD;
        }

        return (int)res;
    }
};

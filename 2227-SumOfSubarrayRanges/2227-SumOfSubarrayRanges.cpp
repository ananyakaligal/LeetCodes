// Last updated: 9/16/2025, 12:01:40 AM
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMin(n), rightMin(n);
        vector<int> leftMax(n), rightMax(n);
        stack<int> st;

        // For minimum
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            leftMin[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            rightMin[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // For maximum
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            leftMax[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            rightMax[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long minSum = 0, maxSum = 0;
        for (int i = 0; i < n; i++) {
            minSum += (long long)nums[i] * leftMin[i] * rightMin[i];
            maxSum += (long long)nums[i] * leftMax[i] * rightMax[i];
        }

        return maxSum - minSum;
    }
};

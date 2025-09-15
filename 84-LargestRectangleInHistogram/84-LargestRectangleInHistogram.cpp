// Last updated: 9/16/2025, 12:09:27 AM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            int currHeight;
            if (i == n)
                currHeight = 0; // Sentinel height at the end
            else
                currHeight = heights[i];

            while (!st.empty() && currHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                int area = height * width;
                if (area > maxArea) {
                    maxArea = area;
                }
            }

            st.push(i);
        }

        return maxArea;
    }
};

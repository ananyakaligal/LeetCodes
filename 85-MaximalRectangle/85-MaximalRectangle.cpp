// Last updated: 9/16/2025, 12:09:26 AM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0, n = heights.size();

        for (int i = 0; i <= n; ++i) {
            int currHeight = (i == n) ? 0 : heights[i];

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
                if (area > maxArea) maxArea = area;
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxArea = 0;
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            int area = largestRectangleArea(heights);
            if (area > maxArea) maxArea = area;
        }

        return maxArea;
    }
};

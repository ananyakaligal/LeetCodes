// Last updated: 9/16/2025, 12:06:50 AM
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        // Min-heap: (sum, i, j)
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;

        // Only push first k elements from nums1 (rows)
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top(); minHeap.pop();
            result.push_back({nums1[i], nums2[j]});

            // Push next element in the current row (if exists)
            if (j + 1 < nums2.size()) {
                minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return result;
    }
};

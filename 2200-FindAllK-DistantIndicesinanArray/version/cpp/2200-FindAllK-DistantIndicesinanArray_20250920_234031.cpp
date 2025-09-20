// Last updated: 9/20/2025, 11:40:31 PM
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> result;

        for (int j = 0; j < n; j++) {
            if (nums[j] == key) {
                // Add all indices i such that |i - j| <= k
                int left = max(0, j - k);
                int right = min(n - 1, j + k);
                for (int i = left; i <= right; i++) {
                    result.insert(i);
                }
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};

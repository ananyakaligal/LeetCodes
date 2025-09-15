// Last updated: 9/16/2025, 12:10:54 AM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array to help easily find triplets
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result; // To store the result triplets

        for (int i = 0; i < n; i++) {
            // Skip duplicates for 'i'
            if (i != 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum > 0) {
                    // If the sum is greater than 0, move the right pointer to the left
                    k--;
                } else if (sum < 0) {
                    // If the sum is less than 0, move the left pointer to the right
                    j++;
                } else {
                    // Found a triplet
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicates for 'j' and 'k'
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return result;
    }
};

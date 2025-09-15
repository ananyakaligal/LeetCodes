// Last updated: 9/16/2025, 12:02:35 AM
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int left = 0, sum = 0, maxSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;
            sum += nums[right];

            // If duplicate found, shrink window from the left
            while (freq[nums[right]] > 1) {
                freq[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

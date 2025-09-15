// Last updated: 9/16/2025, 12:01:01 AM
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long n = nums.size();
        return n * (n + 1) / 2 - countLessThanK(nums, k);
    }

private:
    long long countLessThanK(vector<int>& nums, int k) {
        unordered_map<int, long long> freq;
        long long left = 0, total = 0, pairs = 0;

        for (long long right = 0; right < nums.size(); ++right) {
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            // Shrink the window until pairs < k
            while (pairs >= k) {
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }

            // All subarrays ending at 'right' with start in [left, right] are valid (with < k pairs)
            total += right - left + 1;
        }

        return total;
    }
};

// Last updated: 9/16/2025, 12:00:33 AM
class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isSorted(nums)) {
            int minSum = INT_MAX;
            int index = -1;

            // Find the leftmost pair with the minimum sum
            for (int i = 0; i < nums.size() - 1; ++i) {
                int pairSum = nums[i] + nums[i + 1];
                if (pairSum < minSum) {
                    minSum = pairSum;
                    index = i;
                }
            }

            // Merge the pair
            nums[index] = nums[index] + nums[index + 1];
            nums.erase(nums.begin() + index + 1);
            operations++;
        }

        return operations;
    }
};

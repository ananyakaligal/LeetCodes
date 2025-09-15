// Last updated: 9/16/2025, 12:04:15 AM
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        for (int num : nums) {
            if (num % 2 == 0) evenSum += num;
        }

        vector<int> result;

        for (const auto& query : queries) {
            int val = query[0], index = query[1];

            if (nums[index] % 2 == 0) {
                evenSum -= nums[index];  // Remove old even value
            }

            nums[index] += val;

            if (nums[index] % 2 == 0) {
                evenSum += nums[index];  // Add new even value
            }

            result.push_back(evenSum);
        }

        return result;
    }
};

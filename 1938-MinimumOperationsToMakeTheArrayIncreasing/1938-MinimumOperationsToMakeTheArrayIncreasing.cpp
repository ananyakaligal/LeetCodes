// Last updated: 9/16/2025, 12:02:18 AM
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                int diff = nums[i - 1] - nums[i] + 1;
                operations += diff;
                nums[i] = nums[i - 1] + 1;
            }
        }
        
        return operations;
    }
};

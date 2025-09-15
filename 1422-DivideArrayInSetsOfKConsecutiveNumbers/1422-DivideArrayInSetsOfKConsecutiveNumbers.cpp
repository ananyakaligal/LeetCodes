// Last updated: 9/16/2025, 12:03:20 AM
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;

        map<int, int> count;
        for (int num : nums) count[num]++;

        for (auto& [num, freq] : count) {
            if (freq == 0) continue;

            // Try to form a group starting from num
            for (int i = 1; i < k; i++) {
                if (count[num + i] < freq) return false;
                count[num + i] -= freq;
            }
        }

        return true;
    }
};

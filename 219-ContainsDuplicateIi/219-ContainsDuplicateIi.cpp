// Last updated: 9/16/2025, 12:07:36 AM
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> win;
        int n = nums.size();

        int i = 0, j = 0;
        while (j < n) {
            if (win.find(nums[j]) != win.end()) {
                return true;
            }

            win.insert(nums[j]);

            // Shrink window if size exceeds k
            if (j - i >= k) {
                win.erase(nums[i]);
                i++;
            }

            j++;
        }
        return false;
    }
};

auto init = []() -> int {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        
        for (int i = 0; i < nums.size(); i++) {
            if (seen.count(nums[i])) {
                if (i - seen[nums[i]] <= k) {
                    return true;
                }
            }
            
            seen[nums[i]] = i;
        }
        
        return false; 
    }
};

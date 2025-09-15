// Last updated: 9/16/2025, 12:02:04 AM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        vector<int> total;
        total = nums;

        for(int i = 0; i<nums.size(); i++){
            total.push_back(nums[i]);
        }

        return total;
    }
};
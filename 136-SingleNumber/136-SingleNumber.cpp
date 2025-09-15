// Last updated: 9/16/2025, 12:08:37 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR =0;
        for(int i=0; i<nums.size();i++){
            XOR=XOR^(nums[i]);
        }
        return XOR;
    }
};
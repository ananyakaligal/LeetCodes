// Last updated: 9/16/2025, 12:10:07 AM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current =nums[0];
        int maxi=current;
        for(int i=1;i<nums.size();i++){
            current=max(nums[i],current+nums[i]);
            maxi=max(maxi,current);
        }
        return maxi;
    }
};
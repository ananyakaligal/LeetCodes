// Last updated: 9/16/2025, 12:00:46 AM
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i=1;
        int d=1;
        int maxi=1;

        for(int x=1;x<nums.size();x++){
            if(nums[x-1]<nums[x]){
                i++;
                d=1;
            }
            else if(nums[x-1]>nums[x]) {
                d++;
                i=1;
            }
            else {
                i=1;
                d=1;
            }
            maxi=max(maxi,max(i,d));
        }
        return maxi;
    }
};
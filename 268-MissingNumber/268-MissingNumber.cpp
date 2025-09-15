// Last updated: 9/16/2025, 12:07:15 AM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xo=0,xo2=0;
        for(int i=0;i<n;i++){
            xo^= nums[i];
            xo2^=i;
        }
        xo2=xo2^n;
        return xo2^xo;
    }
};
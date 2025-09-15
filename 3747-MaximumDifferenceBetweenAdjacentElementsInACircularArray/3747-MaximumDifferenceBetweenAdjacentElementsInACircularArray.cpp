// Last updated: 9/16/2025, 12:00:39 AM
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int diff=0;
        for(int i=1;i<n;i++){
            int x = abs(nums[i]-nums[i-1]);
            if(x >diff){
                diff=x;
            }
        }
        if(abs(nums[0]-nums[n-1])>diff) diff=abs(nums[0]-nums[n-1]);
        return diff;
    }
};
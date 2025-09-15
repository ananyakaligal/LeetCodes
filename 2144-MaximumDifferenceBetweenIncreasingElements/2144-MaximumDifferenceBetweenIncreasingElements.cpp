// Last updated: 9/16/2025, 12:01:49 AM
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int i=0,j=1;
        int n= nums.size();
        int diff=-1;
        while(j<n && i<j){
            int d=nums[j]-nums[i];
            if(d<=0){
                if(j-i<2) j++;
                i++;
            }else{
                if(d>diff) diff=d;
                j++;
            }
        }
        return diff;
    }
};
// Last updated: 9/16/2025, 12:05:42 AM
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        double ans = -DBL_MAX;
        int i=0,j=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1==k){
                ans=max(sum,ans);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans/k;
    }
};
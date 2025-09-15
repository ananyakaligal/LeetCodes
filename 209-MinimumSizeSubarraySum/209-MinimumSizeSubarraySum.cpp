// Last updated: 9/16/2025, 12:07:45 AM
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,sum=0;
        int n=nums.size();
        int count=n;
        int sum1=0;

        for(int x=0;x<n;x++){
            sum1+=nums[x];
        }
        if (sum1<target) return 0;
        
        while(j<n){
            sum+=nums[j];

            while(sum>=target){
                count=min(j-i+1,count);
                sum-=nums[i];
                i++;
            }

            j++;
        }
        return count;
    }
};
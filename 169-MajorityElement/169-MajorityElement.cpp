// Last updated: 9/16/2025, 12:08:18 AM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(count==0) max=nums[i];
            if(nums[i]==max){
                count++;
            }else{
                count--;
            }
        }
        return max;
    }
};
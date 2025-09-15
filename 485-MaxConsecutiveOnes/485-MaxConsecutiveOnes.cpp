// Last updated: 9/16/2025, 12:06:19 AM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0, maximum=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==1){count++;
            }
            else{ 
                maximum=max(maximum,count);
                count=0;
            } 
        }
        maximum = max(maximum, count);
        return maximum;
    }
};
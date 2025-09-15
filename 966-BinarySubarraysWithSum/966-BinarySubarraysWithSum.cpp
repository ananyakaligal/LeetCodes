// Last updated: 9/16/2025, 12:04:31 AM
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal > 0) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    } else {
        return atMost(nums, goal);
    }
    }
    
private:
    int atMost(vector<int>& nums, int goal) {
        
        int left = 0, sum = 0, count = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
                                                                                                   
            while (sum > goal) { 
                sum -= nums[left++];
            }

            count += right - left + 1;
        }
        
        return count;
    }
};
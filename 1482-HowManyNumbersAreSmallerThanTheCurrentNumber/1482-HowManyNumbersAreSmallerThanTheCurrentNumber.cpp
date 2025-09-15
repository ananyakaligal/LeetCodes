// Last updated: 9/16/2025, 12:03:06 AM
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(101, 0);
        vector<int> res(n);
        for(int n:nums)
        {
            count[n]++;
        }
        for(int i=1; i<101; i++)
        {
            count[i] += count[i-1]; 
        }
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
            {
                res[i] = 0;
            }
            else
            {
                res[i] = count[nums[i]-1];
            }
        }
        return res;
    }
};
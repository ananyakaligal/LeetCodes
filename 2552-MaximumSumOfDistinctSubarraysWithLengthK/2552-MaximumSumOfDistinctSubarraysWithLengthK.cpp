// Last updated: 9/16/2025, 12:01:06 AM
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int i=0,j=0;
        long long sum=0;
        long long ans=0;
        while(j<nums.size()){
            freq[nums[j]]++;
            sum+=nums[j];
            
            if(j-i+1==k){
                if(freq.size()==k) ans=max(ans,sum);
                freq[nums[i]]--;
                if(freq[nums[i]]==0) freq.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};

// Last updated: 9/16/2025, 12:06:43 AM
class Solution {
private:
    bool isValid(vector<int>& nums, int n, int k, int mid){
        long long partitions=0, runningSum=0;
        for(int i=0;i<n;i++){
            runningSum+=nums[i];
            if(runningSum>mid){
                runningSum=nums[i];
                partitions++;
            }
        }
        if(runningSum>0) partitions++;
        return (partitions<=k);
    }
public:
    int splitArray(vector<int>& nums, int k) {
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0);
        int n=nums.size();

        while(low<high){
            long long mid= low+(high-low)/2;
            if(isValid(nums,n,k,mid)){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
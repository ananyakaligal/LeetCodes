// Last updated: 9/16/2025, 12:05:09 AM
class Solution {
private:
    int BinarySearch(vector<int>& nums, int target,int low,int high){
        if(low>high) return -1;
        int mid=low+((high-low)/2);
        if (nums[mid]==target) return mid;
        else if(nums[mid]>target) return BinarySearch(nums,target,low,high-1);
        else return BinarySearch(nums,target,low+1,high);
    }    
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        int ans=BinarySearch(nums,target,low,high);
        return ans;
    }
};
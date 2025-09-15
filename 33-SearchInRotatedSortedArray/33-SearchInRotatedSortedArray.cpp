// Last updated: 9/16/2025, 12:10:28 AM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<nums[high]){// right array sorted
                if(target>nums[mid] && target <=nums[high]) low=mid+1;
                else high=mid-1;
            }else{ //left array is sorted
                if(target<nums[mid] && target>=nums[low]) high=mid-1;
                else low=mid+1;
            }
        }
        return -1;
    }
};

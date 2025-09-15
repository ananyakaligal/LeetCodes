// Last updated: 9/16/2025, 12:09:32 AM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int x=target;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (nums[mid]==x) return true;
            else if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            else if (nums[mid]<=nums[high]){ //if right is sorted, check there
                if(x>=nums[mid] && x<=nums[high]) low=mid+1;
                else high=mid-1;
            }else{ //left is sorted
                if(x<=nums[mid] && x>=nums[low]) high=mid-1;
                else low=mid+1;
            }
        }
        return false;
    }
};
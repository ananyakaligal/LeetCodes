// Last updated: 9/16/2025, 12:08:20 AM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        int mid=-1;
        while(low<high){
            mid = low + (high-low)/2;
            if(nums[mid]<=nums[high]){//right part being sorted
                high=mid;
            }else{//left part is sorted
                low=mid+1;
            }
        }
        return nums[low];
    }
};
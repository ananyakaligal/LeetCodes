// Last updated: 9/16/2025, 12:01:34 AM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>res(n);
        int l = 0,r = n-1;
        for(int i=0,j=n-1; i<n; i++,j--){
            if(nums[i] < pivot){
                res[l] = nums[i];
                l++;
            }
            if(nums[j] > pivot){
                res[r] = nums[j];
                r--;
            }
        }
        while(l<=r){
            res[l] = pivot;
            l++;
        }
        return res;
    }
};
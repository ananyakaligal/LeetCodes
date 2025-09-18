// Last updated: 9/18/2025, 9:40:00 AM
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0, j=0, k=0;
        int n=nums.size();

        while(j<n){
            if(nums[j]!=val){
                nums[i]=nums[j];
                i++;
                k++;
            }
            j++;
        }
        return k;
    }
};
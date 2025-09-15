// Last updated: 9/16/2025, 12:05:25 AM
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int suffix=0, prefix=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            suffix+=nums[i];
        }
        for(int j=0;j<n;j++){
            suffix-=nums[j];
            if(suffix==prefix) return j;
            prefix+=nums[j];
        }
        return -1;
    }
};
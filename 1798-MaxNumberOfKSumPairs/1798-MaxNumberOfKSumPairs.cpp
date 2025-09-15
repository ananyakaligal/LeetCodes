// Last updated: 9/16/2025, 12:02:38 AM
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0, j=nums.size()-1;
        int count=0;
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum<k) i++;
            else if(sum>k) j--;
            else{
                i++;
                j--;
                count++;
            }
        }
        return count;
    }
};
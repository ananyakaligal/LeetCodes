// Last updated: 9/16/2025, 12:03:31 AM
class Solution {
private:
    int solve(vector<int>& nums, int k){
        int i=0, j=0;
        int n=nums.size();
        int odds=0,maxi=0;
        while(j<n){
            if(nums[j]%2==1) odds++;

            while(odds>k){
                if(nums[i]%2==1) odds-=1;
                i++;
            }
            maxi+=j-i+1;
            j++;
        }
        return maxi;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(k!=0) return solve(nums,k)-solve(nums,k-1);
        return solve(nums,k);
    }
};
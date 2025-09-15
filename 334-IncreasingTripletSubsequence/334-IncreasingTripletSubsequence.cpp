// Last updated: 9/16/2025, 12:06:59 AM
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX;
        int second=INT_MAX;
        int z=nums.size();

        for(int n: nums){
            if(n<=first){
                first=n;
            }else if(n<=second){
                second=n;
            }else{
                return true;
            }
        }
        return false;
    }
};
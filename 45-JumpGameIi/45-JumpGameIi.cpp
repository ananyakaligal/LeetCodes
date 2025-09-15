// Last updated: 9/16/2025, 12:10:16 AM
class Solution {
public:
    int jump(vector<int>& nums) {
        int currEnd=0, farthest=0, jumps=0;
        for(int i=0;i<nums.size()-1;i++){
            farthest=max(farthest,nums[i]+i);

            if(currEnd==i){
                jumps++;
                currEnd=farthest;
            }
        }
        return jumps;
    }
};
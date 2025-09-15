// Last updated: 9/16/2025, 12:08:36 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<32;k++){
            int temp=(1<<k);
            int count=0;

            for(int &num:nums){
                if((num&temp)!=0) count++;
            }

            if(count%3!=0){
                result=result|temp;
            }
        }
        return result;
    }
};
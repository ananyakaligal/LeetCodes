// Last updated: 9/16/2025, 12:04:11 AM
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if (k==0){
            return 0;
        }else{
            return (count(nums, k) - count(nums, k-1));
        }
    }
private:
    int count(vector<int> & nums,int k){
        int l=0, r=0, sum=0,count=0;
        unordered_map<int, int> myMap;

        while(r<nums.size()){
            myMap[nums[r]]++;
             while(myMap.size()>k){
                myMap[nums[l]]--;

                if(myMap[nums[l]]==0) myMap.erase(nums[l]);
                l++;
             }

             count+=r-l+1;
             r++;
        }

    return count;
    }

};
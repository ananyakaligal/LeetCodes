// Last updated: 9/16/2025, 12:08:16 AM
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        vector<int> ans;
        while(i<j){
            int sum=numbers[i]+numbers[j];
            if(sum>target) j--;
            else if(sum<target) i++;
            else{
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
        }
        return ans;
    }
};
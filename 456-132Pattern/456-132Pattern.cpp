// Last updated: 9/16/2025, 12:06:26 AM
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack <int> st;
        int num3=INT_MIN;

        int z=nums.size()-1;
        for(int i=z;i>=0;--i){
            if(nums[i]<num3) return true;
            while(!st.empty() && st.top()<nums[i]){
                num3=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false ;
    }
};
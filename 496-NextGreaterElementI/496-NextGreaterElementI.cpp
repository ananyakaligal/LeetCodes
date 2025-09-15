// Last updated: 9/16/2025, 12:06:17 AM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int> mp;
        stack <int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(!st.empty()){
                mp[nums2[i]]=st.top();
            }else{
                mp[nums2[i]]=-1;
            }
            st.push(nums2[i]);
        }
        vector <int> result;
        for(auto it: nums1){
            result.push_back(mp[it]);
        }
        return result;
    }
};
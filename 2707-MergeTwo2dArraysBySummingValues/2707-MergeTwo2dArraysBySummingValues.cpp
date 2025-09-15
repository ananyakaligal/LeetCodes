// Last updated: 9/16/2025, 12:00:57 AM
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;

        for (auto &v : nums1) {
            mp[v[0]] += v[1];
        }
        for (auto &v : nums2) {
            mp[v[0]] += v[1];
        }

        vector<vector<int>> result;
        for (auto &[a, b] : mp) {
            result.push_back({a, b});
        }
        return result;
    }
};

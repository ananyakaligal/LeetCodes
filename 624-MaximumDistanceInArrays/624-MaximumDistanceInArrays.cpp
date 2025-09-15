// Last updated: 9/16/2025, 12:05:46 AM
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn = arrays[0][0];
        int mx = arrays[0].back();
        int ans = 0;
        for(int i = 1; i < arrays.size(); i++) {
            ans = max(ans, abs(mx-arrays[i].front()));
            ans = max(ans, abs(arrays[i].back() - mn));

            mn = min(mn, arrays[i].front());
            mx = max(mx, arrays[i].back());
        }
        return ans;
    }
};
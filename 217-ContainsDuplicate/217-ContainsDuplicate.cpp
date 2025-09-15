// Last updated: 9/16/2025, 12:07:37 AM
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for(int num:nums){
            if(seen.count(num)){
                return true;
            }
            seen.insert(num);
        }
    return false;
    }
};
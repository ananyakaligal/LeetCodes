// Last updated: 9/16/2025, 12:01:55 AM
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) return {};  // Can't form pairs

        sort(changed.begin(), changed.end());
        unordered_map<int, int> freq;
        vector<int> original;

        for (int num : changed)
            freq[num]++;

        for (int num : changed) {
            if (freq[num] == 0) continue;  // Already used
            if (freq[2 * num] == 0) return {};  // Can't find pair

            original.push_back(num);
            freq[num]--;
            freq[2 * num]--;
        }

        return original;
    }
};

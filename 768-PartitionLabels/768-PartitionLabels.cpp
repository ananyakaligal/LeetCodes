// Last updated: 9/16/2025, 12:05:14 AM
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastIndex;

        // Step 1: Store last index of each character
        for (int i = 0; i < s.size(); ++i) {
            lastIndex[s[i]] = i;
        }

        vector<int> result;
        int start = 0, end = 0;

        // Step 2: Greedy partition
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, lastIndex[s[i]]); // update farthest boundary
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};

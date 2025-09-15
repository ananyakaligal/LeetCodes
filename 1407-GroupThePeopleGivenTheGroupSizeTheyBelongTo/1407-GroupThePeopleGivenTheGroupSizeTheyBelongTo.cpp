// Last updated: 9/16/2025, 12:03:25 AM
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> map;
        vector<vector<int>> result;

        for (int i = 0; i < groupSizes.size(); ++i) {
            int size = groupSizes[i];
            map[size].push_back(i);

            // If we have collected a full group
            if (map[size].size() == size) {
                result.push_back(map[size]);
                map[size].clear();
            }
        }

        return result;
    }
};

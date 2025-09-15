// Last updated: 9/16/2025, 12:10:57 AM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int i = 0;

        while (true) {
            if (i >= strs[0].size()) break;  // Reached end of first string
            char c = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i); 
                }
            }

            i++;  
        }

        return strs[0].substr(0, i);
    }
};

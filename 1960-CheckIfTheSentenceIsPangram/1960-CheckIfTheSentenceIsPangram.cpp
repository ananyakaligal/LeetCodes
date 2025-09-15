// Last updated: 9/16/2025, 12:02:16 AM
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> seen;
        for (char c : sentence) {
            seen.insert(c);
        }
        return seen.size() == 26;
    }
};

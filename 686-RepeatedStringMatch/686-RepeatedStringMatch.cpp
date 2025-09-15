// Last updated: 9/16/2025, 12:05:32 AM
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        // Repeat until length of repeated >= length of b
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        // Check if b is already a substring
        if (repeated.find(b) != string::npos) return count;

        // Try one more repetition (for wrap-around cases)
        repeated += a;
        if (repeated.find(b) != string::npos) return count + 1;

        return -1; // Not possible
    }
};

// Last updated: 9/16/2025, 12:06:29 AM
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Step 1: Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Max heap (pair of freq and char)
        priority_queue<pair<int, char>> maxHeap;

        for (auto& entry : freq) {
            maxHeap.push({entry.second, entry.first});
        }

        // Step 3: Build result string
        string result;

        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();
            result += string(count, ch);
        }

        return result;
    }
};

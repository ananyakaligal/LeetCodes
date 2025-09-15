// Last updated: 9/16/2025, 12:05:47 AM
class Solution {
public:
int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    int maxFreq = 0;
    for (auto &t : tasks) {
        freq[t]++;
        maxFreq = max(maxFreq, freq[t]);
    }

    // Count how many tasks have the max frequency
    int maxCount = 0;
    for (auto &entry : freq) {
        if (entry.second == maxFreq) maxCount++;
    }

    // Calculate intervals
    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int totalIntervals = partCount * partLength + maxCount;

    // Final answer is either calculated or just size of tasks if enough tasks to fill slots
    return max((int)tasks.size(), totalIntervals);
}
};
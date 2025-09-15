// Last updated: 9/16/2025, 12:02:02 AM
class Solution {
public:
    int minTimeToType(string word) {
        int totalTime = 0;
        char prev = 'a';  // initial pointer position

        for (char c : word) {
            int distance = abs(c - prev);
            int minSteps = min(distance, 26 - distance);  // circular steps
            totalTime += minSteps + 1;  // +1 for typing the char
            prev = c;
        }

        return totalTime;
    }
};

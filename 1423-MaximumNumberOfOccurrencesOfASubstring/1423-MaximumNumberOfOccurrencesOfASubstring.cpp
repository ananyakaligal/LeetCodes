// Last updated: 9/16/2025, 12:03:19 AM
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> freq;
        unordered_map<char, int> charCount;
        int maxOccur = 0;

        int i = 0, j = 0;
        while (j < s.size()) {
            charCount[s[j]]++;

            if (j - i + 1 > minSize) {
                charCount[s[i]]--;
                if (charCount[s[i]] == 0) charCount.erase(s[i]);
                i++;
            }

            if (j - i + 1 == minSize) {
                if (charCount.size() <= maxLetters) {
                    string sub = s.substr(i, minSize);
                    freq[sub]++;
                    maxOccur = max(maxOccur, freq[sub]);
                }
            }

            j++;
        }

        return maxOccur;
    }
};

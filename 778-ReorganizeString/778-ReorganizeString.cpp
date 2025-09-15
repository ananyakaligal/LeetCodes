// Last updated: 9/16/2025, 12:05:12 AM
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        int n = s.size();

        for (char c : s) freq[c]++;

        priority_queue<pair<int, char>> pq;
        for (auto [ch, count] : freq) {
            if (count > (n + 1) / 2) return "";
            pq.push({count, ch});
        }

        string result = "";
        pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {
            auto [count, ch] = pq.top(); pq.pop();
            result += ch;

            if (prev.first > 0) pq.push(prev);

            prev = {count - 1, ch};
        }

        return result;
    }
};

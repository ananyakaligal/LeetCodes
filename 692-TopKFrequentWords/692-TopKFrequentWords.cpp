// Last updated: 9/16/2025, 12:05:31 AM
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Step 1: Count frequency
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }

        // Step 2: Use custom comparator for min-heap
        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            // If frequency is different, smaller freq comes first
            if (a.first != b.first)
                return a.first > b.first; // min-heap on freq
            // If frequency is same, lexicographically larger word comes first
            return a.second < b.second; // min-heap on word (reverse order)
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        // Step 3: Maintain heap of size k
        for (const auto& entry : freq) {
            pq.push({entry.second, entry.first});
            if (pq.size() > k)
                pq.pop();
        }

        // Step 4: Extract from heap into result vector
        vector<string> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        // Step 5: Reverse the result because heap gives least frequent first
        reverse(result.begin(), result.end());
        return result;
    }
};
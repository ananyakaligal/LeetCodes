// Last updated: 9/16/2025, 12:03:07 AM
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) freq[num]++;

        priority_queue<int> pq;
        for (auto& [num, count] : freq)
            pq.push(count);

        int removed = 0, count = 0;
        int half = arr.size() / 2;

        while (removed < half) {
            removed += pq.top();
            pq.pop();
            count++;
        }

        return count;
    }
};

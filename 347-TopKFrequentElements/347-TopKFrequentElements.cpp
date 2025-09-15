// Last updated: 9/16/2025, 12:06:54 AM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;

        for(int i=0;i<nums.size();i++){
            freqMap[nums[i]]++;
        }

        // Min heap to keep top k frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;


        for (auto &entry : freqMap) {
            minHeap.push({entry.second, entry.first}); // (freq, num)
            if (minHeap.size() > k) {
                minHeap.pop(); // remove least frequent
            }
        }

        vector <int> results;

        while(!minHeap.empty()){
            int node=minHeap.top().second;
            results.push_back(node);
            minHeap.pop();
        }
        return results;
    }
};

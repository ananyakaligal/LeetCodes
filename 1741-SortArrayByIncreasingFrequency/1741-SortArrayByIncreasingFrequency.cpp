// Last updated: 9/16/2025, 12:02:46 AM
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;

        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second; // larger num first
            return a.first > b.first; // smaller freq first
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for(auto it: nums){
            mp[it]++;
        }

        for(auto &[a,b]: mp){
            minHeap.push({b,a});
        }
        vector<int> result;

        while(!minHeap.empty()){
            int x=minHeap.top().first;
            while(x){
                result.push_back(minHeap.top().second);
                x--;
            }
            minHeap.pop();         
        }
        return result;
    }
};
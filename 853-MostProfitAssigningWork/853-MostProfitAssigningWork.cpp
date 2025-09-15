// Last updated: 9/16/2025, 12:04:56 AM
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        sort(worker.begin(), worker.end());
        
        int totalProfit = 0;
        int jobIndex = 0;
        int maxProfitSoFar = 0;
        
        for (int i = 0; i < worker.size(); i++) {
            while (jobIndex < jobs.size() && jobs[jobIndex].first <= worker[i]) {
                maxProfitSoFar = max(maxProfitSoFar, jobs[jobIndex].second);
                jobIndex++;
            }
            totalProfit += maxProfitSoFar;
        }
        
        return totalProfit;
    }
};

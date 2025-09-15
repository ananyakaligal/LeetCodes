// Last updated: 9/16/2025, 12:04:53 AM
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;

        // Step 1: Calculate wage-to-quality ratio for each worker
        for (int i = 0; i < n; ++i) {
            double ratio = (double)wage[i] / quality[i];
            workers.emplace_back(ratio, quality[i]);
        }

        // Step 2: Sort workers by increasing ratio
        sort(workers.begin(), workers.end());

        // Step 3: Use max-heap to keep track of k smallest qualities
        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double minCost = DBL_MAX;

        for (auto& [ratio, q] : workers) {
            qualitySum += q;
            maxHeap.push(q);

            // Maintain a window of size k
            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }

            // If we have exactly k workers, calculate cost
            if (maxHeap.size() == k) {
                double cost = ratio * qualitySum;
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }
};
 
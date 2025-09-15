// Last updated: 9/16/2025, 12:08:40 AM
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int m = gas.size();
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalCost = accumulate(cost.begin(), cost.end(), 0);

        if (totalCost > totalGas) return -1;

        int curr = 0;
        int start = 0;

        for (int i = 0; i < m; i++) {
            curr += gas[i] - cost[i];

            if (curr < 0) {
                curr = 0;
                start = i + 1;
            }
        }

        return start;
    }
};

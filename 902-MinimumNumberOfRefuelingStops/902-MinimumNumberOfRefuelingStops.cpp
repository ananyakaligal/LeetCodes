// Last updated: 9/16/2025, 12:04:48 AM
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> maxHeap; // to pick largest fuel station
        int fuel = startFuel;
        int stops = 0;
        int i = 0; // index for stations
        int n = stations.size();
        
        while (fuel < target) {
            // Push all reachable stations' fuel into maxHeap
            while (i < n && stations[i][0] <= fuel) {
                maxHeap.push(stations[i][1]);
                i++;
            }
            
            // If can't go further & no station to refuel, return -1
            if (maxHeap.empty()) return -1;
            
            // Otherwise, refuel with the largest station fuel seen so far
            fuel += maxHeap.top();
            maxHeap.pop();
            stops++;
        }
        
        return stops;
    }
};

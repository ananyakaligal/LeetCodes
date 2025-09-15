// Last updated: 9/16/2025, 12:03:48 AM
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Sort trips by start time
        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // Min-heap: {end time, numPassengers}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        int cap=0;

        for(auto& trip: trips){
            int pass=trip[0];
            int from=trip[1];
            int to=trip[2];
            
            while(!pq.empty() && pq.top().first<=from){
                cap-=pq.top().second;
                pq.pop();
            }
            cap+=pass;
            if(cap>capacity) return false;

            pq.push({to,pass});
            
        }
        return true;
    }
};
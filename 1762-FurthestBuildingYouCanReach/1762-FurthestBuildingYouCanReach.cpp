// Last updated: 9/16/2025, 12:02:44 AM
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < heights.size() - 1; i++) {
            int diff = heights[i+1] - heights[i];

            // If we need to climb up
            if (diff > 0) {
                minHeap.push(diff);

                // If we have used more climbs than ladders,
                // use bricks for the smallest climb
                if (minHeap.size() > ladders) {
                    bricks -= minHeap.top();
                    minHeap.pop();
                }

                // If bricks run out, can't proceed
                if (bricks < 0) {
                    return i;
                }
            }
            // else: no bricks or ladders needed for flat/downhill
        }

        // If we finish all buildings
        return heights.size() - 1;
    }
};

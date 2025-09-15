// Last updated: 9/16/2025, 12:05:45 AM
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // Sort by deadline
        sort(courses.begin(), courses.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        priority_queue<int> maxHeap;
        int totalTime = 0;

        for (auto& c : courses) {
            int duration = c[0], lastDay = c[1];

            totalTime += duration;
            maxHeap.push(duration);

            if (totalTime > lastDay) {
                // Remove the longest course to make room
                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};

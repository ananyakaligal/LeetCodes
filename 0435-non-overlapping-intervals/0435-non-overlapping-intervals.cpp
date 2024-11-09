class Solution {
private:
    // Comparator function to sort based on the second element of each subarray
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];  // Compare based on the second element of each vector
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals based on the end time (second element of each subarray)
        sort(intervals.begin(), intervals.end(), comparator);

        int end = intervals[0][1];  // Keep track of the end time of the last non-overlapping interval
        int count = 0;

        for (int i = 1; i < intervals.size(); i++) {
            // If the current interval overlaps with the previous one
            if (intervals[i][0] < end) {
                count++;  // Increment count of intervals to be removed
            } else {
                end = intervals[i][1];  // Update the end time to the current interval's end
            }
        }

        return count;  // The result is the number of intervals to remove
    }
};
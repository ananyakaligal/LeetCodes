// Last updated: 9/16/2025, 12:07:09 AM
class MedianFinder {
private:
    priority_queue<int> maxHeap; // left half (largest on top)
    priority_queue<int, vector<int>, greater<int>> minHeap; // right half (smallest on top)

public:
    MedianFinder() {}

    void addNum(int num) {
        // Always push to maxHeap first
        maxHeap.push(num);

        // Ensure every number in maxHeap <= every number in minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Balance sizes so maxHeap has equal or one more element
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top(); // odd count, middle is top of maxHeap
        }
        // even count, average of two middles
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

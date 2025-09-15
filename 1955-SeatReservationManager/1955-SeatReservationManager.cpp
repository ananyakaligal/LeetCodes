// Last updated: 9/16/2025, 12:02:17 AM
class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
    int nextAvailable;

public:
    SeatManager(int n) {
        nextAvailable = 1;
    }

    int reserve() {
        if (!pq.empty()) {
            int seat = pq.top();
            pq.pop();
            return seat;
        }
        return nextAvailable++;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};


/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
// Last updated: 9/16/2025, 12:00:59 AM
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(), gifts.end());
        
        while (k-- && !pq.empty()) {
            int top = pq.top(); pq.pop();
            pq.push(sqrt(top));
        }
        
        long long sum = 0;
        while (!pq.empty()) {
            sum += pq.top(); pq.pop();
        }
        return sum;
    }
};

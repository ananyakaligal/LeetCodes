class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1;
        int maxSpeed = *max_element(piles.begin(), piles.end()); // Find max pile size
        
        // Binary search 
        while (minSpeed < maxSpeed) {
            int mid = minSpeed + (maxSpeed - minSpeed) / 2;
            if (canFinish(piles, h, mid)) {
                maxSpeed = mid; 
            } else {
                minSpeed = mid + 1; 
            }
        }
        
        return minSpeed; 
    }

private:
    bool canFinish(const vector<int>& piles, int h, int speed) {
        int hours = 0;
        for (int pile : piles) {
            hours = hours + (pile + speed - 1) / speed;
        }
        return hours <= h;
    }
};
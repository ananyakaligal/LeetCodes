// Last updated: 9/16/2025, 12:05:51 AM
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        
        for (int i = 0; i < size; ++i) {
            if (flowerbed[i] == 0) {
                // Check if left and right are also empty or out of bounds
                bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRight = (i == size - 1) || (flowerbed[i + 1] == 0);
                
                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1;  // Plant a flower here
                    count++;
                    if (count >= n) return true;
                }
            }
        }
        
        return count >= n;
    }
};

// Last updated: 9/16/2025, 12:04:12 AM
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        
        //backwards
        while (target > startValue) {
            if (target % 2 == 0) {
                target /= 2;
            } else {
                target += 1;
            }
            count++;
        }
        
        // Add the difference when target is less than or equal to startValue
        return count + (startValue - target);
    }
};

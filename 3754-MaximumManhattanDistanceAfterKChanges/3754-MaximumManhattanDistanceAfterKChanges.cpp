// Last updated: 9/16/2025, 12:00:38 AM
class Solution {
public:
    int maxDistance(string s, int k) {
        int east = 0, west = 0, north = 0, south = 0;
        int maxMD = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'E') east++;
            else if (s[i] == 'W') west++;
            else if (s[i] == 'N') north++;
            else if (s[i] == 'S') south++;

            int currMD = abs(east - west) + abs(north - south);  // Manhattan distance so far
            int steps = i + 1; // Number of steps taken
            int wasted = steps - currMD; // Steps not contributing to max distance

            int extra = 0;
            if (wasted != 0) {
                extra = min(2 * k, wasted);  // You can use changes to recover some wasted steps
            }

            int finalCurrentMD = currMD + extra;
            maxMD = max(maxMD, finalCurrentMD);
        }

        return maxMD;
    }
};

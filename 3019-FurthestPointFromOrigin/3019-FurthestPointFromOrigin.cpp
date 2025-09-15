// Last updated: 9/16/2025, 12:00:51 AM
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0,countBlank = 0;

        for (char c : moves) {
            if (c == 'L') countL++;
            else if (c == 'R') countL--;
            else countBlank++;
        }

        return abs(countL) + countBlank;
    }
};

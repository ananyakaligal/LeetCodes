// Last updated: 9/16/2025, 12:04:40 AM
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string smallest = s;
            for (int i = 1; i < s.size(); ++i) {
                string rotated = s.substr(i) + s.substr(0, i);
                if (rotated < smallest) {
                    smallest = rotated;
                }
            }
            return smallest;
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};

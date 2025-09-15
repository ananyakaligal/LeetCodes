// Last updated: 9/16/2025, 12:01:37 AM
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m = s.length();
        vector<int> result(m);

        for (int i = 0; i < m; i++) {
            int r = startPos[0], c = startPos[1];
            int count = 0;

            for (int j = i; j < m; j++) {
                if (s[j] == 'U') r--;
                else if (s[j] == 'D') r++;
                else if (s[j] == 'L') c--;
                else if (s[j] == 'R') c++;

                if (r < 0 || r >= n || c < 0 || c >= n) break;

                count++;
            }

            result[i] = count;
        }

        return result;
    }
};

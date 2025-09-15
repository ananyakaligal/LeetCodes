// Last updated: 9/16/2025, 12:03:03 AM
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string str = s;  // Make a copy for min version
        int n = s.size();

        // -------- MAX --------
        int i = 0;
        while (i < n && s[i] == '9') i++;
        if (i < n) {
            char x = s[i];
            for (int j = 0; j < n; j++) {
                if (s[j] == x) s[j] = '9';
            }
        }

        // -------- MIN --------
        if (str[0] != '1') {
            char x = str[0];
            for (int j = 0; j < n; j++) {
                if (str[j] == x) str[j] = '1';
            }
        } else {
            int j = 1;
            while (j < n && (str[j] == '0' || str[j] == '1')) j++;
            if (j < n) {
                char x = str[j];
                for (int k = 1; k < n; k++) {
                    if (str[k] == x) str[k] = '0';
                }
            }
        }

        return stoi(s) - stoi(str);
    }
};

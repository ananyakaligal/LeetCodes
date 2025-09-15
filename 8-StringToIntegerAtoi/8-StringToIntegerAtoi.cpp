// Last updated: 9/16/2025, 12:11:05 AM
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        long result = 0;

        // Step 1: Skip leading whitespaces
        while (i < n && s[i] == ' ') i++;

        // Step 2: Sign check
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Process digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: Handle overflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};

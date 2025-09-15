// Last updated: 9/16/2025, 12:06:32 AM
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0; // where to write in the array
        int i = 0;     // read pointer

        while (i < n) {
            char currentChar = chars[i];
            int count = 0;

            // Count how many times the current character repeats
            while (i < n && chars[i] == currentChar) {
                i++;
                count++;
            }

            // Write the character
            chars[index++] = currentChar;

            // If count > 1, write its digits
            if (count > 1) {
                string cnt = to_string(count); // e.g., "12"
                for (char c : cnt) {
                    chars[index++] = c; // write each digit separately
                }
            }
        }

        return index; // new length of the compressed array
    }
};

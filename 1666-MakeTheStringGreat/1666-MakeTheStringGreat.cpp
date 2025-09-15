// Last updated: 9/16/2025, 12:02:54 AM
class Solution {
public:
    string makeGood(string s) {
        string stack = "";

        for (char c : s) {
            if (!stack.empty() && abs(stack.back() - c) == 32) {
                stack.pop_back(); // bad pair found, remove previous char
            } else {
                stack.push_back(c); // no conflict, add to stack
            }
        }

        return stack;
    }
};

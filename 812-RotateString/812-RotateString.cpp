// Last updated: 9/16/2025, 12:05:04 AM
class Solution {
public:
    bool rotateString(string& s, string& goal) {
        return s.size()==goal.size() && (s+s).find(goal)!=-1;
    }
};
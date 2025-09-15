// Last updated: 9/16/2025, 12:02:11 AM
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() > 0 && s.find(part) < s.length()) {
            int index=s.find(part);
            s.erase(index,part.size());
        }
        return s;
    }
};
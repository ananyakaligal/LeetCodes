// Last updated: 9/16/2025, 12:07:47 AM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToT, tToS;

        for (int i = 0; i < s.length(); i++) {
            char sc = s[i];
            char tc = t[i];

            // Check if sc is already mapped and it should map to tc
            if (sToT.count(sc) && sToT[sc] != tc) return false;
            // Check if tc is already mapped and it should map to sc
            if (tToS.count(tc) && tToS[tc] != sc) return false;

            // Establish bidirectional mapping
            sToT[sc] = tc;
            tToS[tc] = sc;
        }

        return true;
    }
};
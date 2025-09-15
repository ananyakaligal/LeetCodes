// Last updated: 9/16/2025, 12:01:09 AM
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        for (string& q : queries) {
            for (string& d : dictionary) {
                int mismatch = 0;
                for (int i = 0; i < q.size(); ++i) {
                    if (q[i] != d[i]) mismatch++;
                    if (mismatch > 2) break;
                }
                if (mismatch <= 2) {
                    result.push_back(q);
                    break; // no need to check further dictionaries
                }
            }
        }

        return result;
    }
};

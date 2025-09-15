// Last updated: 9/16/2025, 12:02:29 AM
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size(); // number of users
        vector<unordered_set<int>> lang(m+1); // 1-indexed users

        // store languages each user knows
        for (int i = 0; i < m; i++) {
            for (int l : languages[i]) {
                lang[i+1].insert(l);
            }
        }

        // Step 1: find problematic users
        unordered_set<int> problematic;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int l : lang[u]) {
                if (lang[v].count(l)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                problematic.insert(u);
                problematic.insert(v);
            }
        }

        if (problematic.empty()) return 0;

        // Step 2: try each language
        vector<int> count(n+1, 0);
        for (int u : problematic) {
            for (int l : lang[u]) {
                count[l]++;
            }
        }

        int max_known = 0;
        for (int l = 1; l <= n; l++) {
            max_known = max(max_known, count[l]);
        }

        // Step 3: result
        return (int)problematic.size() - max_known;
    }
};

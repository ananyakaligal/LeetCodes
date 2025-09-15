// Last updated: 9/16/2025, 12:00:34 AM
class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> Ymax;
        int m = x.size();
        int n=y.size();

for (int i = 0; i < m; i++) {
        if (Ymax.find(x[i]) != Ymax.end()) {
            Ymax[x[i]] = max(Ymax[x[i]], y[i]);
        } else {
            Ymax[x[i]] = y[i];
        }
    }
    vector<int> values;
    for (auto& p : Ymax) {
        values.push_back(p.second);
    }
        int z=values.size();
        if(z<3) return -1;
        sort(values.begin(),values.end());
        int sum=values[z-3]+values[z-1]+values[z-2];

        return sum;
    }
};
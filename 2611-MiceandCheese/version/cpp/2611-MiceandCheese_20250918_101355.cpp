// Last updated: 9/18/2025, 10:13:55 AM
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> diff(n);
        int sum = 0;

        // assume all cheeses are eaten by mouse2
        for (int i = 0; i < n; i++) {
            sum += reward2[i];
            diff[i] = reward1[i] - reward2[i];
        }

        // pick the k cheeses with largest advantage for mouse1
        sort(diff.begin(), diff.end(), greater<int>());

        for (int i = 0; i < k; i++) {
            sum += diff[i]; 
        }

        return sum;
    }
};

// Last updated: 9/16/2025, 12:03:18 AM
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start);
        visited[start] = true;   // mark as visited when pushing

        while (!q.empty()) {
            int ind = q.front();
            q.pop();

            if (arr[ind] == 0) return true;

            // move forward
            if (ind + arr[ind] < n && !visited[ind + arr[ind]]) {
                visited[ind + arr[ind]] = true;
                q.push(ind + arr[ind]);
            }

            // move backward
            if (ind - arr[ind] >= 0 && !visited[ind - arr[ind]]) {
                visited[ind - arr[ind]] = true;
                q.push(ind - arr[ind]);
            }
        }

        return false;
    }
};

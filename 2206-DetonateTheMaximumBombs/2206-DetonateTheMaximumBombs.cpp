// Last updated: 9/16/2025, 12:01:45 AM
class Solution {
public:
    // DFS to simulate the chain reaction
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, graph, visited);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n); // adjacency list

        // Step 1: Build the graph
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1];
                long long dx = x2 - x1, dy = y2 - y1;
                if (dx * dx + dy * dy <= r1 * r1) {
                    graph[i].push_back(j); // bomb i can reach bomb j
                }
            }
        }

        // Step 2: Try detonating each bomb and simulate
        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n, false);
            dfs(i, graph, visited);
            int count = 0;
for (bool detonated : visited) {
    if (detonated) count++;
}

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};

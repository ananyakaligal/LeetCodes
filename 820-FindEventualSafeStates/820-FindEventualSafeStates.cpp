// Last updated: 9/16/2025, 12:04:58 AM
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);

        // Build reversed graph
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                revGraph[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        // Terminal nodes (no outgoing edges in original graph) have indegree 0 in reversed graph
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for (int prev : revGraph[node]) {
                indegree[prev]--;
                if (indegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        sort(safe.begin(), safe.end()); // because problem needs them sorted
        return safe;
    }
};


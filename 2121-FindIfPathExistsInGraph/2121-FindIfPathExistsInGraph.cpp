// Last updated: 9/16/2025, 12:01:54 AM
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        
        // Build adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        // DFS function
        function<bool(int)> dfs = [&](int node) {
            if (node == destination) return true;
            visited[node] = true;

            for (int nbr : adj[node]) {
                if (!visited[nbr]) {
                    if (dfs(nbr)) return true;
                }
            }
            return false;
        };

        return dfs(source);
    }
};

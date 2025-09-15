// Last updated: 9/16/2025, 12:04:42 AM
class Solution {
private:
    bool dfs(int node, int c, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = c;

        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - c, color, graph))
                    return false;
            } else if (color[neighbor] == c) {
                return false; // conflict found
            }
        }

        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);

        // Build undirected graph
        for (auto &edge : dislikes) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> color(n, -1); // -1 = uncolored

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph))
                    return false;
            }
        }

        return true;
    }
};

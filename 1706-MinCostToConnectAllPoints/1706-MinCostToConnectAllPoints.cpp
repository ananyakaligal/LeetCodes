// Last updated: 9/16/2025, 12:02:50 AM
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false; // Already connected, skip

        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<tuple<int, int, int>> edges; // {weight, u, v}

        // Step 1: Generate all edges with their Manhattan distances
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        // Step 2: Sort edges by weight
        sort(edges.begin(), edges.end());

        // Step 3: Kruskal's using DSU
        DSU dsu(n);
        int totalCost = 0, edgesUsed = 0;

        for (auto& [cost, u, v] : edges) {
            if (dsu.unite(u, v)) {
                totalCost += cost;
                edgesUsed++;
                if (edgesUsed == n - 1) break; // MST complete
            }
        }

        return totalCost;
    }
};


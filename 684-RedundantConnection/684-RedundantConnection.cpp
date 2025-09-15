// Last updated: 9/16/2025, 12:05:33 AM
class DSU {
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n+1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    bool unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false; // cycle detected
        parent[py] = px;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        
        for (auto& edge : edges) {
            if (!dsu.unionSet(edge[0], edge[1])) {
                return edge;  // this edge creates a cycle
            }
        }
        return {};
    }
};

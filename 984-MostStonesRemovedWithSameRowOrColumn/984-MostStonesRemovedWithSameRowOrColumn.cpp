// Last updated: 9/16/2025, 12:04:25 AM
class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;

        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        int offset = maxRow + 1;  // Ensures column indices don't overlap with row indices
        DisjointSet ds(maxRow + maxCol + 2);

        unordered_set<int> uniqueNodes;

        for (auto& stone : stones) {
            int rowNode = stone[0];
            int colNode = stone[1] + offset;

            ds.unionByRank(rowNode, colNode);

            uniqueNodes.insert(rowNode);
            uniqueNodes.insert(colNode);
        }

        int components = 0;
        for (int node : uniqueNodes) {
            if (ds.findParent(node) == node)
                components++;
        }

        return stones.size() - components;
    }
};

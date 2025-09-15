// Last updated: 9/16/2025, 12:03:14 AM
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

    bool unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return false; // already connected

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }

    int countUniqueParents(int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (findParent(i) == i)
                count++;
        }
        return count;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) 
            return -1; // Not enough cables

        DisjointSet ds(n);
        int redundant = 0;

        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            int pu = ds.findParent(u);
            int pv = ds.findParent(v);

            if(!ds.unionByRank(u, v)) redundant++;
        }

        int components = ds.countUniqueParents(n);
        int needed = components - 1;

        return (redundant >= needed) ? needed : -1;
    }
};
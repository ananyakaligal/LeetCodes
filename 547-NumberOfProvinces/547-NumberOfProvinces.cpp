// Last updated: 9/16/2025, 12:06:04 AM
class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) 
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

    int countUniqueParents(int n) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            if (findParent(i) == i)
                count++;
        }
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    ds.unionByRank(i, j);
                }
            }
        }

        return ds.countUniqueParents(n);
    }
};
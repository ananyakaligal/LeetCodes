// Last updated: 9/16/2025, 12:05:24 AM
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);

        unordered_map<string, int> emailToIndex;

        // Step 1: Map each email to an account index, and union if the email already seen
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string email = accounts[i][j];
                if (emailToIndex.find(email) == emailToIndex.end()) {
                    emailToIndex[email] = i;
                } else {
                    ds.unionByRank(i, emailToIndex[email]);
                }
            }
        }

        // Step 2: Group emails by their representative (parent)
        unordered_map<int, set<string>> merged;
        for (auto& [email, index] : emailToIndex) {
            int parentIndex = ds.findParent(index);
            merged[parentIndex].insert(email);
        }

        // Step 3: Build final result
        vector<vector<string>> result;
        for (auto& [index, emailSet] : merged) {
            vector<string> curr;
            curr.push_back(accounts[index][0]); // account name
            curr.insert(curr.end(), emailSet.begin(), emailSet.end()); // sorted emails
            result.push_back(curr);
        }

        return result;
    }
};

// Last updated: 9/16/2025, 12:03:37 AM
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> prob(n, 0.0);
        prob[start] = 1.0;

        priority_queue<pair<double, int>> pq;  // {probability, node}
        pq.push({1.0, start});

        while (!pq.empty()) {
            auto [currProb, u] = pq.top(); pq.pop();
            if (u == end) return currProb;

            for (auto &[v, p] : adj[u]) {
                double newProb = currProb * p;
                if (newProb > prob[v]) {
                    prob[v] = newProb;
                    pq.push({newProb, v});
                }
            }
        }

        return 0.0;
    }
};

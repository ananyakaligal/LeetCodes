// Last updated: 9/16/2025, 12:05:05 AM
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for (auto &e : flights) {
            adjList[e[0]].push_back({e[1], e[2]});
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, src, 0});

        vector<int> minStops(n, INT_MAX);

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top(); pq.pop();

            if (u == dst) return cost;

            minStops[u] = stops;

            for (auto &[v, w] : adjList[u]) {
                if (stops < k + 1 && stops + 1 < minStops[v]) {
                    pq.push({cost + w, v, stops + 1});
                }
            }
        }

        return -1;
    }
};
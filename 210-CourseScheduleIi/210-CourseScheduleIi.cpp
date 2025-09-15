// Last updated: 9/16/2025, 12:07:44 AM
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        queue<int> q;

        for (auto x : prerequisites) {
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int node = q.front(); q.pop();
            ans.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return (ans.size() == numCourses) ? ans : vector<int>{};
    }
};

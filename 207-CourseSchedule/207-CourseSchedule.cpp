// Last updated: 9/16/2025, 12:07:46 AM
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;
            for (const int neigh : adj[node]) {
                if (--inDegree[neigh] == 0) q.push(neigh);
            }
        }

        return count == numCourses;
    }
};

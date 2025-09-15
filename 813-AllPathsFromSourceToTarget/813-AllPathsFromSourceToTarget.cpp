// Last updated: 9/16/2025, 12:05:02 AM
class Solution {
public:
    void dfs(int node, vector<vector<int>> &graph, vector<int> &path, vector<vector<int>> &ans) {
        path.push_back(node);

        if (node == graph.size() - 1) {
            ans.push_back(path);
        } else {
            for (int neighbor : graph[node]) {
                dfs(neighbor, graph, path, ans);
            }
        }

        path.pop_back(); // backtrack
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(0, graph, path, ans);
        return ans;
    }
};
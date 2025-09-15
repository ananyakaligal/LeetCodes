// Last updated: 9/16/2025, 12:01:41 AM
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;

        // Build graph
        for (int i = 0; i < recipes.size(); ++i) {
            for (string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        // Initialize queue with initial supplies
        queue<string> q;
        for (string& s : supplies) q.push(s);

        vector<string> result;

        // Topological sort
        while (!q.empty()) {
            string curr = q.front(); q.pop();

            for (string& next : graph[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                    result.push_back(next);
                }
            }
        }

        return result;
    }
};

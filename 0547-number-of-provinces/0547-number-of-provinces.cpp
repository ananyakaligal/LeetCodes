class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& visited) {
        visited[node] = 1; // Mark the node as visited

        // Explore all neighbors
        for (int neighbor : adjLs[node]) {
            if (!visited[neighbor]) { // If not visited
                dfs(neighbor, adjLs, visited); // Recursively visit the neighbor
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjLs(V); // Adjacency list for the graph
        vector<int> visited(V, 0); // Vector to keep track of visited nodes

        // Build the adjacency list from the isConnected matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    // Note: We do not need to add the reverse edge in the DFS
                }
            }
        }

        int count = 0;

        // Iterate through all nodes to find connected components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) { 
                count++; 
                dfs(i, adjLs, visited); // Perform DFS
            }
        }

        return count;
    }
};

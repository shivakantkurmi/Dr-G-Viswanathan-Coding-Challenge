/*
Bridge edge in a graph
Difficulty: MediumAccuracy: 34.61%Submissions: 65K+Points: 4
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u,v] represents the edge between the vertices u and v. Determine whether a specific edge between two vertices (c, d) is a bridge.

Note:

An edge is called a bridge if removing it increases the number of connected components of the graph.
if there’s only one path between c and d (which is the edge itself), then that edge is a bridge.
*/
class Solution {
    void dfs(int node, vector<int> adj[], vector<int>& visited, int c, int d) {
        visited[node] = 1;
        for (auto x : adj[node]) {
            if ((node == c && x == d) || (node == d && x == c)) continue;
            if (!visited[x]) {
                dfs(x, adj, visited, c, d);
            }
        }
    }

public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Step 1: Build adjacency list from edge list
        vector<int> adj[V];
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: DFS from one end, skipping the edge (c, d)
        vector<int> visited(V, 0);
        dfs(c, adj, visited, c, d);

        // Step 3: If 'd' is not visited after skipping edge, it's a bridge
        return !visited[d];
    }
};

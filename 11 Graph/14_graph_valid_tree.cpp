/*
    https://neetcode.io/problems/valid-tree?list=neetcode250

    Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

    n = 5
    edges = [[0, 1], [0, 2], [0, 3], [1, 4]]

    Output:
    true
*/

class Solution {
private:
    bool dfs(int node, int prev, vector<int>adj[], vector<int>& visited) {
        visited[node] = 1;

        for(auto it:adj[node]) {
            if(!visited[it]) {
                if(dfs(it, node, adj, visited)) return true;
            }
            else if(it != prev)   return true;
        }

        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];

        for(auto it:edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>visited(n, 0);
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                cnt++;
                if(dfs(i, -1, adj, visited))   return false;
            }
        }

        // more than 1 connected compoenents
        if(cnt > 1) return false;

        return true;
    }
};

/*
    http://neetcode.io/problems/count-connected-components?list=neetcode250

    There is an undirected graph with n nodes. There is also an edges array, where edges[i] = [a, b] means that there is an edge between node a and node b in the graph.

    The nodes are numbered from 0 to n - 1.

    Return the total number of connected components in that graph.


    Input:
    n=3
    edges=[[0,1], [0,2]]
    Output:
    1
*/

class Solution {
private:
    void dfs(int node, vector<int>&visited, vector<int>adj[]) {
        visited[node] = true;
        for(auto it:adj[node]) {
            if(!visited[it])    dfs(it, visited, adj);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto it:edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        vector<int>visited(n, 0);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, visited, adj);
                cnt++;
            }
        }

        return cnt;
    }
};
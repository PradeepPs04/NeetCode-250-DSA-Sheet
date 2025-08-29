/*
    https://leetcode.com/problems/max-area-of-island/description/

    You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

    The area of an island is the number of cells with a value 1 in the island.

    Return the maximum area of an island in grid. If there is no island, return 0.


    Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
    Output: 6
*/

class Solution {
public:
    int dfs(vector<vector<int>>& grid, int cr, int cc, vector<vector<int>>& visited) {
        // mark as visited
        visited[cr][cc] = true;

        vector<int>rows = {0, -1, 0, +1};
        vector<int>cols = {-1, 0, +1, 0};

        int count = 1;
        for(int i = 0; i < 4; i++) {
            int nr = cr + rows[i];
            int nc = cc + cols[i];

            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1 && !visited[nr][nc]) {
                count += dfs(grid, nr, nc, visited);
            }
        }

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));

        int maxi = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    maxi = max(maxi, dfs(grid, i, j, visited));
                }
            }
        }

        return maxi;
    }
};
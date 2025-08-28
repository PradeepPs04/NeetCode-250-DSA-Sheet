/*
    https://leetcode.com/problems/number-of-islands/submissions/1750919516/

    Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


    Input: grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
    ]
    Output: 1
*/

    class Solution {
public:
    void dfs(vector<vector<char>>& grid, int cr, int cc, vector<vector<int>>& visited) {
        visited[cr][cc] = true;

        vector<int>rows = {0, -1, 0, 1};
        vector<int>cols = {-1, 0, 1, 0};

        for(int i = 0; i < 4; i++) {
            int nr = cr + rows[i];
            int nc = cc + cols[i];

            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == '1' && !visited[nr][nc])    dfs(grid, nr, nc, visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
        
        int count = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }

        return count;
    }
};
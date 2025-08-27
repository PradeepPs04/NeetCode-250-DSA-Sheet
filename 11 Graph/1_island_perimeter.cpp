/*
    https://leetcode.com/problems/island-perimeter/description/

    You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

    Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

    The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.


    Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
    Output: 16
*/

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        // if out of bound (means water) or in the water
        if(i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || grid[i][j] == 0)   return 1;

        // if already visited
        if(visited[i][j] == 1)  return 0;

        // mark as visited
        visited[i][j] = 1;

        // go in all directions
        int ans = 0;
        ans += dfs(i, j-1, grid, visited);
        ans += dfs(i-1, j, grid, visited);
        ans += dfs(i, j+1, grid, visited);
        ans += dfs(i+1, j, grid, visited); 

        return ans;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>>visited(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) return dfs(i, j, grid, visited);
            }
        }

        return 0;
    }
};
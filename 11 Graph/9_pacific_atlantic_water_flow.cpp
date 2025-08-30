/*
    https://leetcode.com/problems/pacific-atlantic-water-flow/description/

    There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

    The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

    The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

    Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

    Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
*/

class Solution {
private:
    int n, m;
    vector<vector<int>>atlantic, pacific;
    vector<int>rows, cols;

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int cr, int cc) {
        // mark current cell as visited
        visited[cr][cc] = true;

        // call dfs in all valid directions
        for(int i = 0; i < 4; i++) {
            int nr = cr + rows[i];
            int nc = cc + cols[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && heights[nr][nc] >= heights[cr][cc]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.size() == 0) return {};

        n = heights.size();
        m = heights[0].size();

        atlantic = vector<vector<int>>(n, vector<int>(m, 0));
        pacific = vector<vector<int>>(n, vector<int>(m, 0));

        rows = {0, -1, 0, +1};
        cols = {-1, 0, +1, 0};

        // call dfs from pacific and atlantic (left & right side)
        for(int i = 0; i < n; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, m-1);
        }

        // call dfs from pacific and atlantic (top & bottom side)
        for(int j = 0; j < m; j++) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, n-1, j);
        }

        // get all the cells that are rechable from both pacific and atlantic ocean
        vector<vector<int>>ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
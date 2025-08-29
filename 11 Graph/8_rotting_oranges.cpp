/*
    https://leetcode.com/problems/rotting-oranges/

    You are given an m x n grid where each cell can have one of three values:

        - 0 representing an empty cell,
        - 1 representing a fresh orange, or
        - 2 representing a rotten orange.
    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

    Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>>q; // {time, {row, col}}

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) q.push({0, {i, j}});
            }
        }

        int rows[] = {0, -1, 0, +1};
        int cols[] = {-1, 0, +1, 0};

        int ans = 0;
        while(!q.empty()) {
            int time = q.front().first;
            int cr = q.front().second.first;
            int cc = q.front().second.second;
            q.pop();

            ans = max(ans, time);

            for(int i = 0; i < 4; i++) {
                int nr = cr + rows[i];
                int nc = cc + cols[i];

                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == 1) {
                    q.push({time+1, {nr, nc}});
                    // mark orange as rotten
                    grid[nr][nc] = 2;
                }
            }
        }

        // check if any orange is still fresh
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};
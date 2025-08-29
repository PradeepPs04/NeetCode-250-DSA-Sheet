/*
    https://neetcode.io/problems/islands-and-treasure?list=neetcode250

    You are given a m×n 2D grid initialized with these three possible values:

        => -1 - A water cell that can not be traversed.
        => 0 - A treasure chest.
        => INF - A land cell that can be traversed. We use the integer 2^31 - 1 = 2147483647 to represent INF.

    Fill each land cell with the distance to its nearest treasure chest. If a land cell cannot reach a treasure chest then the value should remain INF.

    Assume the grid can only be traversed up, down, left, or right.

    Modify the grid in-place.

    Input: [
    [2147483647,-1,0,2147483647],
    [2147483647,2147483647,2147483647,-1],
    [2147483647,-1,2147483647,-1],
    [0,-1,2147483647,2147483647]
    ]

    Output: [
    [3,-1,0,1],
    [2,2,1,-1],
    [1,-1,2,-1],
    [0,-1,3,4]
    ]
*/

class Solution {
private:
    int rows[4] = {0,-1,0,+1};
    int cols[4] = {-1,0,+1,0};

    void dfs(vector<vector<int>>& grid, int cr, int cc, int distance) {
        grid[cr][cc] = distance;

        for(int i = 0; i < 4; i++) {
            int nr = cr + rows[i];
            int nc = cc + cols[i];

            if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && distance < grid[nr][nc]) {
                dfs(grid, nr, nc, distance+1);
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0)  dfs(grid, i, j, 0);
            }
        }
    }
};


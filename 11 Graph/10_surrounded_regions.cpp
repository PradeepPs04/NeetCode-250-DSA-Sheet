/*
    https://leetcode.com/problems/surrounded-regions/

    You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

        - Connect: A cell is connected to adjacent cells horizontally or vertically.
        - Region: To form a region connect every 'O' cell.
        - Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
    To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

    Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
*/

class Solution {
private:
    int n, m;
    vector<vector<int>>visited;
    vector<int>rows, cols;

    void dfs(vector<vector<char>>& board, int cr, int cc) {
        visited[cr][cc] = true;

        // go in all possible valid directions
        for(int i = 0; i < 4; i++) {
            int nr = cr + rows[i];
            int nc = cc + cols[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && board[nr][nc] == 'O') {
                dfs(board, nr, nc);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        visited = vector<vector<int>>(n, vector<int>(m, 0));
        rows = {0, -1, 0, +1};
        cols = {-1, 0, +1, 0};

        // call dfs from all valid edges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && !visited[i][j] && board[i][j] == 'O') {  
                    cout<<i<<":"<<j<<endl;
                    dfs(board, i, j);
                }
            }
        }



        // now check which are the regions that are not reachable from edge regions
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};
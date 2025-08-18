/*
    https://leetcode.com/problems/word-search/description/

    Given an m x n grid of characters board and a string word, return true if word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true
*/

class Solution {
private:
    int n, m;
    vector<vector<int>>visited;
public:
    bool solve(vector<vector<char>>& board, string& word, int cr, int cc, int idx) {
        // if word is found
        if(idx == word.length())    return true;

        // if in the wrong cell
        if(cr < 0 || cr == n || cc < 0 || cc == m)  return false;
        if(board[cr][cc] != word[idx])  return false;
        if(visited[cr][cc]) return false;

        // mark current cell as visited
        visited[cr][cc] = 1;

        // check all neighbours
        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nr = cr + rows[i];
            int nc = cc + cols[i];

            if(solve(board, word, nr, nc, idx+1))   return true;
        }

        // mark current cell as unvisited for next calls
        visited[cr][cc] = 0;

        // word not found
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        visited = vector<vector<int>>(n, vector<int>(m, 0));

        // check for all starting points
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0] && solve(board, word, i, j, 0))   return true;
            }
        }

        return false;
    }
};
/*
    https://leetcode.com/problems/n-queens-ii/description/

    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

    Given an integer n, return the number of distinct solutions to the n-queens puzzle.

    Input: n = 4
    Output: 2
*/

class Solution {
public:
    bool possible(int row, int col, int n, vector<string>& board) {
        int i = row;
        int j = col;

        // check left top diagonal
        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q')  return false;
            i--;
            j--;
        }

        // check left side
        i = row;
        j = col;
        while(j >= 0) {
            if(board[i][j] == 'Q')  return false;
            j--;
        }

        // check left bottom diagonal
        i = row;
        j = col;

        while(i < n && j >= 0) {
            if(board[i][j] == 'Q')  return false;
            i++;
            j--;
        }

        return true;
    }    

    int solve(int col, int n, vector<string>& board, int &ans) {
        if(col == n) return 1;

        int cnt = 0;

        for(int row = 0; row < n; row++) {
            if(possible(row, col, n, board))
            {
                board[row][col] = 'Q';
                cnt += solve(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }

        return cnt;
    }

    int totalNQueens(int n) {
        // create an empty board of size n*n
        vector<string>board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++)  board[i] = s;
        
        int ans = 0;
        return solve(0, n, board, ans);
    }
};
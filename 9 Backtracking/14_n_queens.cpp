/*
    https://leetcode.com/problems/n-queens/description/

    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

    Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

    Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.


    Input: n = 4
    Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
*/

class Solution {
private:
    bool isPossible(vector<string>& board, int row, int col, int n)
    {
        int i = row;
        int j = col;

        // checking for left upper diagonal
        while(i >=0 && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        i = row;
        j = col;
        // checking for left row
        while(j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            j--;
        }

        i = row;
        j = col;
        // checking for left lower diagonal
        while(i < n && j >= 0)
        {
            if(board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        return true;
    }
    void generate(int n, int col, vector<string> &board, vector<vector<string>>& ans)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++)
        {
            if(isPossible(board, row, col, n))
            {
                board[row][col] = 'Q';
                generate(n, col + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        string s(n, '.');    // create a string of size n with all dots (.)
        vector<string> board(n); // chess board 
       
        // filling the board with dots (.) 
        // n size board where all has a n size string filled with dots (.)
        for(int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        generate(n, 0, board, ans);
        return ans;
    }
};
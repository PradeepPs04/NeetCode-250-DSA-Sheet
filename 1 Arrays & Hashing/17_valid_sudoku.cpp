/*
    Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
    Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.


    Input: board = 
        [["5","3",".",".","7",".",".",".","."]
        ,["6",".",".","1","9","5",".",".","."]
        ,[".","9","8",".",".",".",".","6","."]
        ,["8",".",".",".","6",".",".",".","3"]
        ,["4",".",".","8",".","3",".",".","1"]
        ,["7",".",".",".","2",".",".",".","6"]
        ,[".","6",".",".",".",".","2","8","."]
        ,[".",".",".","4","1","9",".",".","5"]
        ,[".",".",".",".","8",".",".","7","9"]]
    Output: true


    Input: board = 
        [["8","3",".",".","7",".",".",".","."]
        ,["6",".",".","1","9","5",".",".","."]
        ,[".","9","8",".",".",".",".","6","."]
        ,["8",".",".",".","6",".",".",".","3"]
        ,["4",".",".","8",".","3",".",".","1"]
        ,["7",".",".",".","2",".",".",".","6"]
        ,[".","6",".",".",".",".","2","8","."]
        ,[".",".",".","4","1","9",".",".","5"]
        ,[".",".",".",".","8",".",".","7","9"]]
    Output: false
    Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
*/

// Approach 1
class Approach1 {
public:
    bool valid(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        set<char> st;
        for (int row = sr; row <= er; row++) {
            for (int col = sc; col <= ec; col++) {
                if (board[row][col] == '.')
                    continue;

                if (st.find(board[row][col]) != st.end())
                    return false;

                st.insert(board[row][col]);
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // check all rows
        for (int row = 0; row < 9; row++) {
            set<char> st;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;

                if (st.find(board[row][col]) != st.end())
                    return false;

                st.insert(board[row][col]);
            }
        }

        // check all cols
        for (int col = 0; col < 9; col++) {
            set<char> st;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.')
                    continue;

                if (st.find(board[row][col]) != st.end())
                    return false;

                st.insert(board[row][col]);
            }
        }

        // check 3*3 boxes
        for (int sr = 0; sr < 9; sr += 3) {
            int er = sr + 2; // end row
            for (int sc = 0; sc < 9; sc += 3) {
                int ec = sc + 2; // end cols
                if (!valid(board, sr, er, sc, ec))
                    return false;
            }
        }

        return true;
    }
};


// Apprach 2
class Approach2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if(board[i][j] == '.')  continue;

                string row = to_string(board[i][j]) + "found at row " + to_string(i);
                string col = to_string(board[i][j]) + "found at col " + to_string(j);
                string box = to_string(board[i][j]) + "found at " + to_string(i/3) + to_string(j/3);

                if(st.find(row) != st.end() || st.find(col) != st.end() || st.find(box) != st.end())
                    return false;
                
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }

        return true;
    }
};
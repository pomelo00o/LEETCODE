/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto check_row = checkRow(board);
        auto check_col = checkCol(board);
        auto check_square = checkSquare(board);
        return check_row && check_col && check_square;
    }

    bool checkRow(vector<vector<char>>& board) {
        for (int row = 0; row < board.size(); ++row) {
            bitset<9> bset;
            for (int col = 0; col < board[row].size(); ++col) {
                if (board[row][col] >= '1' && board[row][col] <= '9') {
                    if (bset[board[row][col] - '1']) {
                        return false;
                    } else {
                        bset.set(board[row][col] - '1');
                    }
                }
            }
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board) {
        int size = board[0].size();
        for (int col = 0; col < size; ++col) {
            bitset<9> bset;
            for (int row = 0; row < board.size(); ++row) {
                if (board[row][col] >= '1' && board[row][col] <= '9') {
                    if (bset[board[row][col] - '1']) {
                        return false;
                    } else {
                        bset.set(board[row][col] - '1');
                    }
                }
            }
        }
        return true;
    }

    bool checkSquare(vector<vector<char>>& board) {
        for (int squareRow = 0; squareRow < 3; ++squareRow) {
            for (int squareCol = 0; squareCol < 3; ++squareCol) {
                bitset<9> bset;
                for (int row = squareRow * 3; row < squareRow * 3 + 3; ++ row) {
                    for (int col = squareCol * 3; col < squareCol * 3 + 3; ++ col) {
                        if (board[row][col] >= '1' && board[row][col] <= '9') {
                            if (bset[board[row][col] - '1']) {
                                return false;
                            } else {
                                bset.set(board[row][col]- '1');
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};


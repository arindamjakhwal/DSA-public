
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false); // row - col + n - 1
        vector<bool> diag2(2 * n - 1, false); // row + col

        backtrack(0, n, board, col, diag1, diag2, ans);

        return ans;
    }

private:
    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& col, vector<bool>& diag1,
                   vector<bool>& diag2,
                   vector<vector<string>>& ans) {
        // All queens have been placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            int d1 = row - c + n - 1;
            int d2 = row + c;

            // Check whether this position is safe
            if (col[c] || diag1[d1] || diag2[d2]) {
                continue;
            }

            // Place queen
            board[row][c] = 'Q';
            col[c] = diag1[d1] = diag2[d2] = true;

            // Place queen in the next row
            backtrack(row + 1, n, board, col, diag1, diag2, ans);

            // Backtrack: remove queen
            board[row][c] = '.';
            col[c] = diag1[d1] = diag2[d2] = false;
        }
    }
};

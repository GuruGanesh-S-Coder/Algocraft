#include "Solver.hpp"

void Solver::solve(int row, int n, std::vector<std::string>& board,
                   std::vector<std::vector<std::string>>& solutions,
                   std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
            continue;

        board[row][col] = 'Q';
        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

        solve(row + 1, n, board, solutions, cols, diag1, diag2);

        board[row][col] = '.';
        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
    }
}

bool Solver::solveNQueens(int n, std::vector<std::vector<std::string>>& solutions) {
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
    solve(0, n, board, solutions, cols, diag1, diag2);
    return !solutions.empty();
}

int Solver::longestCommonSubsequence(const std::string& text1, const std::string& text2) {
    int m = text1.size(), n = text2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

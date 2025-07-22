#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>
#include <string>

class Solver {
public:
    // N-Queens Backtracking
    bool solveNQueens(int n, std::vector<std::vector<std::string>>& solutions);

    // Longest Common Subsequence using DP
    int longestCommonSubsequence(const std::string& text1, const std::string& text2);

private:
    void solve(int row, int n, std::vector<std::string>& board, std::vector<std::vector<std::string>>& solutions,
               std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2);
};

#endif // SOLVER_HPP

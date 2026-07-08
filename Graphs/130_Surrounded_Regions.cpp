/*
LeetCode 130

Problem:
Surrounded Regions

Topic:
Graph, Depth-First Search (DFS)

Approach:
Any 'O' connected to the boundary cannot be surrounded.

1. Perform DFS from all boundary 'O' cells.
2. Mark all reachable 'O' cells as '#'.
3. Traverse the board:
   - Convert remaining 'O' to 'X'
   - Convert '#' back to 'O'

Time Complexity: O(m × n)
Space Complexity: O(m × n)
*/

class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n ||
            board[i][j] != 'O')
            return;

        board[i][j] = '#';

        dfs(i + 1, j, board);
        dfs(i - 1, j, board);
        dfs(i, j + 1, board);
        dfs(i, j - 1, board);
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        if (m == 0 || n == 0)
            return;

        // First and last column
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board);

            if (board[i][n - 1] == 'O')
                dfs(i, n - 1, board);
        }

        // First and last row
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                dfs(0, j, board);

            if (board[m - 1][j] == 'O')
                dfs(m - 1, j, board);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

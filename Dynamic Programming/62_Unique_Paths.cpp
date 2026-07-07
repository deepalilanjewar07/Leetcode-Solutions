/*
LeetCode 62

Problem:
Unique Paths

Topic:
Dynamic Programming

Approach:
Use Dynamic Programming with space optimization.

Let dp[j] represent the number of unique paths to reach
the current cell in the current row.

Transition:
dp[j] = dp[j] + dp[j - 1]

where:
dp[j]     -> paths from above
dp[j - 1] -> paths from left

Time Complexity: O(m × n)
Space Complexity: O(n)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};

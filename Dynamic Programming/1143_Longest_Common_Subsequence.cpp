/*
LeetCode 1143

Problem:
Longest Common Subsequence

Topic:
Dynamic Programming

Approach:
Use 2D Dynamic Programming.

Let dp[i][j] denote the length of the longest common
subsequence between:
text1[0...i-1] and text2[0...j-1]

Transition:
If characters match:
    dp[i][j] = 1 + dp[i-1][j-1]

Otherwise:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Time Complexity: O(m × n)
Space Complexity: O(m × n)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

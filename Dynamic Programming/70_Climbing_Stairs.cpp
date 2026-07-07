/*
LeetCode 70

Problem:
Climbing Stairs

Topic:
Dynamic Programming

Approach:
The number of ways to reach the current stair is the sum
of the ways to reach the previous two stairs.

Transition:
dp[i] = dp[i - 1] + dp[i - 2]

Since only the previous two values are needed, optimize
the space to O(1).

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int climbStairs(int n) {

        if (n <= 2)
            return n;

        int prev2 = 1;
        int prev1 = 2;

        for (int i = 3; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

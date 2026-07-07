/*
LeetCode 509

Problem:
Fibonacci Number

Topic:
Dynamic Programming

Approach:
Use the Fibonacci recurrence:
F(n) = F(n-1) + F(n-2)

Since only the previous two values are needed,
optimize the space to O(1).

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int fib(int n) {

        if (n <= 1)
            return n;

        int prev2 = 0;
        int prev1 = 1;

        for (int i = 2; i <= n; i++) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

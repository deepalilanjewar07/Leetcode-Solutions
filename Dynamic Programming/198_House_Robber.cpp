/*
LeetCode 198

Problem:
House Robber

Topic:
Dynamic Programming

Approach:
At each house, we have two choices:
1. Rob the current house and add its money to the maximum
   profit up to two houses back.
2. Skip the current house and keep the previous maximum profit.

Transition:
current = max(prev1, prev2 + nums[i])

where:
prev1 -> maximum profit till previous house
prev2 -> maximum profit till house before previous

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int rob(vector<int>& nums) {

        int prev1 = 0;
        int prev2 = 0;

        for (int money : nums) {
            int current = max(prev1, prev2 + money);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

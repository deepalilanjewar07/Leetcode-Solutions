/*
LeetCode 123

Problem:
Best Time to Buy and Sell Stock III

Topic:
Dynamic Programming

Approach:
Maintain four states:
1. buy1  - Maximum profit after first buy.
2. sell1 - Maximum profit after first sell.
3. buy2  - Maximum profit after second buy.
4. sell2 - Maximum profit after second sell.

For each price, update these states in order to simulate
at most two transactions.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy1 = INT_MIN;
        int sell1 = 0;
        int buy2 = INT_MIN;
        int sell2 = 0;

        for (int price : prices) {
            buy1 = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);

            buy2 = max(buy2, sell1 - price);
            sell2 = max(sell2, buy2 + price);
        }

        return sell2;
    }
};

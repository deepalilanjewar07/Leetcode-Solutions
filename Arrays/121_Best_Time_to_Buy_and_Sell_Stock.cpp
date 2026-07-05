/*
LeetCode 121

Topic: Arrays

Approach:
- Track the minimum price seen so far.
- Calculate maximum profit.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int price : prices){
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};

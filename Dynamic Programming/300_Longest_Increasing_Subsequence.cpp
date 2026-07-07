/*
LeetCode 300

Problem:
Longest Increasing Subsequence

Topic:
Dynamic Programming, Binary Search

Approach:
Maintain a list 'tails' where tails[i] stores the smallest
possible tail of an increasing subsequence of length (i + 1).

For each number:
- If it is greater than all elements in tails, append it.
- Otherwise, replace the first element in tails that is
  greater than or equal to it using lower_bound().

The size of tails is the length of the LIS.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> tails;

        for (int num : nums) {

            auto it = lower_bound(tails.begin(), tails.end(), num);

            if (it == tails.end())
                tails.push_back(num);
            else
                *it = num;
        }

        return tails.size();
    }
};

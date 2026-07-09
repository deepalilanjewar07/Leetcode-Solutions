/*
LeetCode 112

Problem:
Path Sum

Topic:
Binary Tree, Depth-First Search (DFS)

Approach:
Traverse the tree using DFS while subtracting the current
node's value from the target sum.

If a leaf node is reached and the remaining target equals
the leaf's value, a valid root-to-leaf path exists.

Time Complexity: O(N)
Space Complexity: O(H)

where:
N = number of nodes
H = height of the tree
*/

class Solution {
public:

    bool hasPathSum(TreeNode* root, int targetSum) {

        if (!root)
            return false;

        if (!root->left && !root->right)
            return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

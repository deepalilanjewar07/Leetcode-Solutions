/*
LeetCode 104

Problem:
Maximum Depth of Binary Tree

Topic:
Binary Tree, Depth-First Search (DFS)

Approach:
Recursively compute the maximum depth of the left and right
subtrees.

The depth of the current node is:
1 + max(leftDepth, rightDepth)

Time Complexity: O(N)
Space Complexity: O(H)

where:
N = number of nodes
H = height of the tree
*/

class Solution {
public:

    int maxDepth(TreeNode* root) {

        if (!root)
            return 0;

        return 1 + max(maxDepth(root->left),
                       maxDepth(root->right));
    }
};

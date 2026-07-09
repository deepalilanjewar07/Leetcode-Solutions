/*
LeetCode 113

Problem:
Path Sum II

Topic:
Binary Tree, Depth-First Search (DFS), Backtracking

Approach:
Perform a DFS traversal while maintaining the current path
and remaining target sum.

- Add the current node to the path.
- If a leaf node is reached and the remaining sum equals
  the node's value, store the current path.
- Backtrack by removing the current node before returning.

Time Complexity: O(N)
Space Complexity: O(H)

where:
N = number of nodes
H = height of the tree
*/

class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {

        if (!root)
            return;

        path.push_back(root->val);

        if (!root->left && !root->right &&
            targetSum == root->val) {

            result.push_back(path);
        }

        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        dfs(root, targetSum);

        return result;
    }
};

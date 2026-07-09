/*
LeetCode 958

Problem:
Check Completeness of a Binary Tree

Topic:
Binary Tree, Breadth-First Search (BFS)

Approach:
Perform a level-order traversal.

A complete binary tree must not have any non-null node
after the first null node encountered during BFS.

Algorithm:
1. Traverse the tree using a queue.
2. Once a null node is seen, set a flag.
3. If any non-null node appears after the flag is set,
   the tree is not complete.

Time Complexity: O(N)
Space Complexity: O(N)

where:
N = number of nodes
*/

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        bool nullSeen = false;

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                nullSeen = true;
            } else {

                if (nullSeen)
                    return false;

                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};

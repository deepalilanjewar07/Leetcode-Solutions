/*
LeetCode 99

Problem:
Recover Binary Search Tree

Topic:
Binary Search Tree, Inorder Traversal, Depth-First Search (DFS)

Approach:
The inorder traversal of a BST should produce a sorted sequence.

If two nodes are swapped:
- The first misplaced node is where prev->val > current->val
  occurs for the first time.
- The second misplaced node is the current node whenever an
  inversion is found.

After traversal, swap the values of the two misplaced nodes.

Time Complexity: O(N)
Space Complexity: O(H)

where:
N = number of nodes
H = height of the tree
*/

class Solution {
public:

    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {

        if (!root)
            return;

        inorder(root->left);

        if (prev && prev->val > root->val) {

            if (!first)
                first = prev;

            second = root;
        }

        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {

        inorder(root);

        swap(first->val, second->val);
    }
};

/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDepth;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);
        maxDepth = max(maxDepth, leftDepth + rightDepth);
        return 1 + max(leftDepth, rightDepth);
    }
};


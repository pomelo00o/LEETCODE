/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
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
private:
    int deepest = 0;
    TreeNode* lca = nullptr;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        helper(root, 0);
        return lca;
    }

    int helper(TreeNode* n, int depth) {
        deepest = max(deepest, depth);
        if (!n) return depth;
        int left = helper(n->left, depth + 1);
        int right = helper(n->right, depth + 1);
        if (left == deepest && right == deepest) lca = n;
        return max(left, right);
    }
};


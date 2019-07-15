/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }

    int helper(TreeNode* root, int res) {
        if (!root) return 0;
        if (!root->left && !root->right) return res * 10 + root->val;
        return helper(root->left, res * 10 + root->val) + helper(root->right, res * 10 + root->val);
    }
};


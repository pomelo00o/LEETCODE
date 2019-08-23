/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
    TreeNode* increasingBST(TreeNode* root, TreeNode* next = nullptr) {
        if (!root) return next;
        TreeNode* res = increasingBST(root->left, root);
        root->left = nullptr;
        root->right = increasingBST(root->right, next);
        return res;
    }
};


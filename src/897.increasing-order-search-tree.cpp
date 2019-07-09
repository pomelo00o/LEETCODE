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
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = nullptr) {
        if (!root) return tail;
        auto res = increasingBST(root->left, root);
        root->left = nullptr;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};


/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int pathSum(TreeNode* root, int target) {
        if (!root) return 0;
        return pathSumFromThisNode(root, target) + pathSum(root->left, target) + pathSum(root->right, target);
    }

    int pathSumFromThisNode(TreeNode* node, int target) {
        if (!node) return 0;
        return (node->val == target) + pathSumFromThisNode(node->left, target - node->val) + pathSumFromThisNode(node->right, target - node->val);
    }
};


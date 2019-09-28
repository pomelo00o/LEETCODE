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
        int fromCurr = count(root, target);
        int fromLeft = pathSum(root->left, target);
        int fromRight = pathSum(root->right, target);
        return fromCurr + fromLeft + fromRight;
    }

    int count(TreeNode* node, int target) {
        if (!node) return 0;
        int fromCurr = (node->val == target) ? 1 : 0;
        int fromLeft = count(node->left, target - node->val);
        int fromRight = count(node->right, target - node->val);
        return fromCurr + fromLeft + fromRight;
    }
};


/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxValue = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxValue;
    }

    int helper(TreeNode* node) {
        if(!node) return 0;
        int left = max(0, helper(node->left));
        int right = max(0, helper(node->right));
        maxValue = max(maxValue, left + right + node->val);
        return max(left, right) + node->val;
    }
};


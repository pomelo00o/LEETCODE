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
private:
    int maxLen = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxLenFromThisNode(root);
        return maxLen;
    }

    int maxLenFromThisNode(TreeNode* node) {
        if (!node) return 0;
        int left = maxLenFromThisNode(node->left);
        int right = maxLenFromThisNode(node->right);
        maxLen = max(maxLen, left + right);
        return 1 + max(left, right);
    }
 
};


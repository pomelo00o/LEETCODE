/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        // flatten both sides into list
        flatten(root->left);
        flatten(root->right);

        TreeNode* tmp = root->right;

        // append the original left tree to the root node
        root->right = root->left;
        root->left = nullptr;

        // append the original right tree at the end
        while (root->right) {
            root = root->right;
        }
        root->right = tmp;
    }
};


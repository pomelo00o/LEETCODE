/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val > key) 
            root->left = deleteNode(root->left, key);
        else if (root->val < key) 
            root->right = deleteNode(root->right, key);
        else {
            if (!root->right) {
                TreeNode* left = root->left;
                delete root;
                return left;
            } else {
                TreeNode* min = findMinNode(root->right);
                root->val = min->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }

    TreeNode* findMinNode(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }
};


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
        if (root->val == key) {
            if (!root->right) {
                return root->left;
            } else {
                TreeNode* right = root->right;
                while (right->left) right = right->left;
                swap(root->val, right->val);
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};


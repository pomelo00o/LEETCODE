/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 && !root2) return false;
        if (!root1 && root2) return false;
        if (!root1 && !root2) return true;
        // if flip odd times --> flip(r1.left, r2.right) && flip(r2.left, r1.right)
        // if flip even times --> flip(r1.left, r1.right) && flip(r2.left, r2.right)
        return (root1->val == root2->val) && ((flipEquiv (root1->right, root2->left) && flipEquiv (root1->left, root2->right)) || (flipEquiv (root1->left, root2->left) && flipEquiv (root1->right, root2->right)));
    }
};


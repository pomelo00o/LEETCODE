/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        helper(res, root, to_string(root->val));
        return res;
    }

    void helper(vector<string>& res, TreeNode* root, string t) {
        if (!root->left && !root->right) {
            res.push_back(t);
            return;
        }
        if (root->left) {
            helper(res,root->left, t + "->" + to_string(root->left->val));
        }
        if (root->right) {
            helper(res, root->right, t + "->" + to_string(root->right->val));
        }
    }
};


/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }

    void helper(TreeNode* root, int depth, vector<vector<int>>& res) {
        if (!root) return;
        if (res.size() == depth) res.push_back(vector<int>());
        res[depth].push_back(root->val);
        helper(root->left, depth + 1, res);
        helper(root->right, depth + 1, res);
    }
};


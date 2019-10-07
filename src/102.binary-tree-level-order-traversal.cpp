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
        int depth = 0;
        dfs(res, depth, root);
        return res;
    }

    void dfs(vector<vector<int>>& res, int depth, TreeNode* root) {
        if (!root) return;
        if (res.size() == depth) res.push_back(vector<int>());
        res[depth].push_back(root->val);
        dfs(res, depth + 1, root->left);
        dfs(res, depth + 1, root->right);
    }
};


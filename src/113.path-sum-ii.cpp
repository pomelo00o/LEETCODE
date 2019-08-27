/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res = {};
        vector<int> curr = {};
        dfs(root, sum, res, curr);
        return res;
    }

    void dfs(TreeNode* root, int target, vector<vector<int>>& res, vector<int>& curr) {
        if (!root) return;
        curr.push_back(root->val);
        if (root->val == target && !root->left && !root->right) 
            res.push_back(curr);
        if (root->left)
            dfs(root->left, target - root->val, res, curr);
        if (root->right)
            dfs(root->right, target - root->val, res, curr);
        curr.pop_back();
    }
};


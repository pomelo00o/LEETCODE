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
        vector<vector<int>> paths;
        vector<int> path;
        findPath(root, sum, paths, path);
        return paths;
    }

    void findPath(TreeNode* root, int sum, vector<vector<int>>& paths, vector<int>& path) {
        if (!root) return;
        path.push_back(root->val);
        if (root->val == sum && !root->left && !root->right) {
            paths.push_back(path);
        }
        findPath(root->left, sum - root->val, paths, path);
        findPath(root->right, sum - root->val, paths, path);
        path.pop_back();
    }
};


/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
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
    int widthOfBinaryTree(TreeNode* root) {
        // vec[level] : <start, end>
        // length = vec[level].second - vec[level].first + 1
        return dfs(root, 0, 1, vector<pair<int, int>>() = {});
    }

    int dfs(TreeNode* root, int level, unsigned int order, vector<pair<int, int>>& vec) {
        if (!root) return 0;
        if (vec.size() == level) vec.push_back({order, order});
        else vec[level].second = order;
        return max({vec[level].second - vec[level].first + 1, dfs(root->left, level + 1, 2 * order, vec), dfs(root->right, level + 1, 2 * order + 1, vec)});
    }
};


/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> nodes;
        nodes.push(root);
        bool needReverse = false;
        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> row(size);
            for (int i = 0; i < size; ++i) {
                auto node = nodes.front();
                nodes.pop();
                int idx = needReverse ? (size - 1 - i) : i;
                row[idx] = node->val;
                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }
            needReverse = !needReverse;
            res.push_back(row);
        }
        return res;
    }
};


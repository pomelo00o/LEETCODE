/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

// @lc code=start
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res = {};
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* rightmostNode;
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                rightmostNode = q.front();
                q.pop();
                if (rightmostNode->left) {
                    q.push(rightmostNode->left);
                }
                if (rightmostNode->right) {
                    q.push(rightmostNode->right);
                }
            }
            res.push_back(rightmostNode->val);
        }
        return res;
    }
};
// @lc code=end


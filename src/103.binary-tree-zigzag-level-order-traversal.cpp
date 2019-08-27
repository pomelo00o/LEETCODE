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
        // a simple bfs
        // initialize a queue with root node
        // pop the front node and push its left and right nodes into the queue
        // use a flag variable to indicate whether reverse is needed
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool reverse = false;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> curr(sz);
            for (int i = 0; i < sz; ++i) {
                TreeNode* tmp = q.front();
                q.pop();
                if (!reverse) curr[i] = tmp->val;
                else curr[sz - i - 1] = tmp->val;
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            reverse = !reverse;
            res.push_back(curr);
        }
        return res;
    }
};


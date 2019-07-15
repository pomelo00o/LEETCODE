/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        vector<int> vals;
        vector<TreeNode*> nodes;
        inorder(root, vals, nodes);
        sort(vals.begin(), vals.end());
        for (int i = 0; i < nodes.size(); ++i) {
            nodes[i]->val = vals[i];
        }
    }

    void inorder(TreeNode* root, vector<int>& vals, vector<TreeNode*>& nodes) {
        if (!root) return;
        inorder(root->left, vals, nodes);
        vals.push_back(root->val);
        nodes.push_back(root);
        inorder(root->right, vals, nodes);
    }
};


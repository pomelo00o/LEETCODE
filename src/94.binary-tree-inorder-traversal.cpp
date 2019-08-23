/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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

// recursive way
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (root->left)
            traverse(root->left, res);
        res.push_back(root->val);
        if (root->right)
            traverse(root->right, res);
    }
};

// iterative way
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};

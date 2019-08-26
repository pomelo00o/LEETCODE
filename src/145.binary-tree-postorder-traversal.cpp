/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        // recursive way
        vector<int> res;
        helper(res, root);
        return res;

        // iterative way
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* last = nullptr;
        if (!root) return {};
        while (root || !(stk.empty())) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                TreeNode* curr = stk.top();
                if (curr->right && curr->right != last) root = curr->right;
                else {
                    res.push_back(curr->val);
                    last = curr;
                    stk.pop();
                }
            }
        }
        return res;
    }

    void helper(vector<int>& res, TreeNode* root) {
        if (!root) return;
        helper(res, root->left);
        helper(res, root->right);
        res.push_back(root->val);
    }

};

